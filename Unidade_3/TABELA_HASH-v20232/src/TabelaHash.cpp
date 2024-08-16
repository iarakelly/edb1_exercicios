//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        Par<string, string>* entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}

/**
 Este método deve inserir na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    if (this->fatorDeCarga() >= CARGA_LIMITE_SUPERIOR)
    {
        this->aumentar();
    }
    auto indiceINICIAL = this->hash(chave);
    int indiceRemovido = -1;

    for (size_t delta = 0; delta < this->getTamanho(); delta++)
    {
        auto indice = (indiceINICIAL+delta) % this->getTamanho();
        auto elementoATUAL = this->tabela[indice];

        if (elementoATUAL == nullptr)
        {
            auto novo = new Par<std::string, std::string>(chave, valor);
            if ( indiceRemovido == -1)
            {
                this->tabela[indice] = novo;
            }
            else if(indiceRemovido != -1)
            {
                this->tabela[indiceRemovido] = novo;
            }

            ++ this->quantidade;
            return true;
        }
        else if (elementoATUAL == REMOVIDO)
        {
            if (indiceRemovido == -1)
            {
                indiceRemovido = indice;
            }
            else
            {
                continue;
            }
        }
        else if(elementoATUAL != REMOVIDO && elementoATUAL->getChave() == chave)
        {
            elementoATUAL->setValor(valor);
            return true;
        }

    }
    return false;
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    auto indiceInicial = this->hash(chave);

    for (size_t delta = 0; delta < this->getTamanho(); ++ delta )
    {
        auto indice = ( indiceInicial + delta ) % this->getTamanho();
        auto elementoAtual = this->tabela[indice];

        if (elementoAtual == nullptr) 
        {
            return "NÃO ACHOU";
        } 
        else if(elementoAtual == REMOVIDO)
        {
            continue;
        }
        else if (elementoAtual->getChave() == chave)
        {
            return elementoAtual->getValor();
        }

    }
    return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
    if (this->fatorDeCarga() <= CARGA_LIMITE_INFERIOR)
    {
        this->diminuir();
    }

    auto indiceInicial = this->hash(chave);

    for (size_t delta = 0; delta < this->getTamanho(); delta++)
    {
        auto indice = ( indiceInicial + delta ) % this->getTamanho();
        auto elementoAtual = this->tabela[indice];

        if(elementoAtual == nullptr )
        {
            return false;
        }
        else if(elementoAtual == REMOVIDO)
        {
            continue;
        }
        else if (elementoAtual->getChave() == chave)
        {
            delete this->tabela[indice];
            this->tabela[indice] = REMOVIDO;
            quantidade--;
            return true;
        }
    } 
    return false;
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
    auto tamanhoVelho = this->getTamanho();
    this->tamanho = tamanhoNovo;

    auto arrayNovo = new Par<std::string, std::string>*[tamanhoNovo];

    for( std::size_t i = 0; i < tamanhoNovo; i++ )
    {
        arrayNovo[i] = nullptr;
    }

    for (auto i = 0; i < tamanhoVelho; i ++)
    {
        auto atual = this->tabela[i];

        if(atual != nullptr && atual != REMOVIDO)
        {
            auto chave = atual->getChave();
            auto indiceInicial = this->hash(chave);

            for (auto j = 0; j < tamanhoNovo; j ++)
            {
                auto indice = (indiceInicial + j ) % tamanhoNovo;

                if (arrayNovo[indice] == nullptr)
                {
                   arrayNovo[indice] == atual;
                   break;
                }
            }
        }
    }
    delete[] this->tabela;
    this->tabela = arrayNovo;    
}

std::size_t TabelaHash::preHash(const string chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

bool TabelaHash::verificarDuplicatas()
{
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->tabela[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = tabela[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
