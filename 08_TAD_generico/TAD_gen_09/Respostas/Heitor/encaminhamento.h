#ifndef _ENCAMINHAMENTO_H
#define _ENCAMINHAMENTO_H

/*
    Estrutura do tipo Encaminhamento contendo os atributos necessários para a manipulação
*/
typedef struct _Encaminhamento Encaminhamento;

/*
    Função que cria um encaminhamento e retorna o seu endereço de memória
    @param nomePaciente: nome do paciente para quem o encaminhamento foi prescrita
    @param nomeMedico: nome do médico que prescreveu o encaminhamento
    @param especialidade: especialidade
    @param motivo: motivo
    @return: endereço de memória do exame criada
*/
Encaminhamento *criaEncaminhamento(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo);

/*
    Função que lê os dados de um encaminhamento a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória do exame lido
*/
Encaminhamento *leEncaminhamento();

/*
    Função que calcula o preço de impressão de um encaminhamento de acordo com a especificação
    @param dado: ponteiro genérico para o encaminhamento a ser calculado
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão do encaminhamento
*/
float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere);

/*
    Função que imprime um encaminhamento de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para o encaminhamento a ser impresso
*/
void imprimeEncaminhamento(void *dado);

/*
    Função que desaloca um encaminhamento
    @param dado: ponteiro genérico para o encaminhamento a ser desalocado
*/
void desalocaEncaminhamento(void *dado);

#endif