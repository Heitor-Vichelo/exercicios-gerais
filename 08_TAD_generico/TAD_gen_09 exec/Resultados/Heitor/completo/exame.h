#ifndef _EXAME_H
#define _EXAME_H

/*
    Estrutura do tipo Exame contendo os atributos necessários para a manipulação
*/
typedef struct _Exame Exame;

/*
    Função que cria um exame e retorna o seu endereço de memória
    @param nomePaciente: nome do paciente para quem a exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu o exame
    @param descricao: justificativa para o exame
    @return: endereço de memória do exame criada
*/
Exame *criaExame(char *nomeMedico, char *nomePaciente, char *descricao);

/*
    Função que lê os dados de um exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória do exame lido
*/
Exame *leExame();

/*
    Função que calcula o preço de impressão de um exame de acordo com a especificação
    @param dado: ponteiro genérico para o exame a ser calculado
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão do exame
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere);

/*
    Função que imprime um exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para o exame a ser impresso
*/
void imprimeExame(void *dado);

/*
    Função que desaloca um exame
    @param dado: ponteiro genérico para o exame a ser desalocado
*/
void desalocaExame(void *dado);

#endif