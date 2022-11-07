#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <vector>
#define QUANT_CURSOS 7
#define QUANT_DISCIPLINAS 8

using namespace std;

// criação da primeira struct
struct Disciplinas{
    char nomeprofessor[60];
    char nomedisciplina[50];
    float notas[2][2]; // a variavel notas é uma matriz com duas linhas e duas colunas 
};
struct Curso{ // criação da segunda struct 
    int disciplinas;
    int duracao;
    char nomecurso[50];
   struct Disciplinas Disci[8];// trazendo a struct  disciplinas dentro da struct curso
};
struct Aluno{ // crição de ultima de struct 
    char nomealuno[60];
    int codigoacademico;
    int cpf;
    char endereco[50];
    char complemento[30];
    struct Curso Cur;
};
 // criamos uma variavel do tipo struct aluno
 struct Aluno Alu;
 vector<Aluno> alunosCadastrados;

 
 void init(struct Curso cursos_disponiveis[QUANT_CURSOS]);
 int main()
 {   
    struct Curso cursos_disponiveis[QUANT_CURSOS];
    init(cursos_disponiveis);
    
    int opcao;
    int opcao_curso;
    do{
        printf("1 - Adicionar um novo cadastro\n");
    printf("2 - Alterar dados do alunos\n");
    printf("3 - Pesquisar cadastro do aluno\n");
    printf("4 - Exluir cadastro do aluno\n");
    printf("5 - Encerrar programa\n ");
    printf ("qual das opcão voce deseja escolher\n");
    scanf("%d", &opcao);
 
    switch (opcao){
     
    // Cadastro do Aluno
    case 1: // pode cadastra o aluno com espaço 
    printf("Cadastrar aluno\n");
    printf ("Digite o nome do aluno\n");
    scanf(" %[^\n]", Alu.nomealuno);
     
     printf("Digite o código academico do aluno\n");
     scanf("%d", &Alu.codigoacademico);
     
    printf("Digite o CPF do aluno\n");
    scanf("%d", &Alu.cpf);
     
    printf("Digite o endereço do aluno\n");
    scanf(" %[^\n]", Alu.endereco);
     
    printf("Digite o complemento do aluno\n");
    scanf(" %[^\n]", Alu.complemento);
    
    for (int i = 0; i < QUANT_CURSOS; i++) {
        printf("Curso %d: %s %d anos\n", i+1, cursos_disponiveis[i].nomecurso,cursos_disponiveis[i].duracao);
    }
    
    printf("\nSelecione o curso deste aluno: ");
    scanf("%d", &opcao_curso);
    
    // Caso o usuário digite uma opção inválida
    Alu.Cur = cursos_disponiveis[opcao_curso-1];
    if (opcao_curso > 7 || opcao_curso < 1) {
        printf("Curso não disponível D:");
        break;
    }
    
    printf("Você selecionou o curso %s.\n", Alu.Cur.nomecurso);
    printf("\nAs disciplinas deste curso são:\n");
    for (int i = 0; i < QUANT_DISCIPLINAS; i++) {
        printf("%s\n", Alu.Cur.Disci[i].nomedisciplina);
        printf("%s\n", Alu.Cur.Disci[i].nomeprofessor);
        
        float media;
        printf("Digite a primeira nota\n");
        scanf ("%f", &Alu.Cur.Disci[i].notas[0][0]);
        printf("Digite a segunda  nota\n");
        scanf ("%f", &Alu.Cur.Disci[i].notas[0][1]);
        printf("Digite a nota da APS\n");
        scanf ("%f", &Alu.Cur.Disci[i].notas[1][0]);
        
        float nota1 = Alu.Cur.Disci[i].notas[0][0];
        float nota2 = Alu.Cur.Disci[i].notas[0][1];
        float APS = Alu.Cur.Disci[i].notas[1][0];
     
        media = (nota1 + nota2 + APS) / 3;
        Alu.Cur.Disci[i].notas[1][1] = media;
    }
    
     alunosCadastrados.push_back(Alu);
    printf("\nO aluno '%s' foi cadastrado com sucesso!\n", Alu.nomealuno);
    break;
     
    case 2 :
    
     printf("Modificar dados do aluno\n");
     
     int codigopesquisado;
     printf("Digite o codigo acadêmico pesquisado do aluno\n");
     scanf("%d", &codigopesquisado);
     
     int alunoEncontrado;
    alunoEncontrado = 0; 
     for(vector<Aluno>::iterator aluno = alunosCadastrados.begin(); aluno != alunosCadastrados.end(); aluno++){
         if (aluno->codigoacademico == codigopesquisado){
             alunoEncontrado = 1; // o numero 1 simboliza o true que seria (verdadeiro)
             printf("o aluno foi encontrado : %s\n", aluno->nomealuno);
             
             int alternativa;
         printf ("o que voce deseja alterar?\n");
         
         printf("1 - Endereço :\n");
         printf("2 - Curso :\n");
         printf("3 - complemento :\n");
         printf("Escolha algumas dessas alternativa \n");
         scanf("%d",&alternativa);
         
         switch(alternativa){
             
             case 1:
               printf("Digite um novo endereço :\n");
               scanf(" %[^\n]", aluno->endereco);
               
               printf ("o aluno %s mudou-se para o endereco %s\n",aluno->nomealuno, aluno->endereco);
               break;
               
             case 2 : 
             
             for (int i = 0; i < QUANT_CURSOS; i++){
                 printf("Curso %d: %s %d anos\n", i+1, cursos_disponiveis[i].nomecurso,cursos_disponiveis[i].duracao);
             }
               printf("Digite um novo curso :\n");
               scanf("%d",&opcao_curso);
               
               Alu.Cur = cursos_disponiveis[opcao_curso-1];
               if (opcao_curso > 7 || opcao_curso < 1) {
                printf("Curso não disponível D:");
                break;
             }
               
               printf("o aluno %s mudou se para o curso %s\n",aluno->nomealuno , aluno->Cur.nomecurso);
                
               break;
               
             case 3 : 
               printf("Digite um novo complemento\n");
               scanf (" %[^\n]", aluno->complemento);
               
               printf( "o aluno %s mudou para complemento %s\n",aluno->nomealuno , aluno->complemento);
               break;
               
             default: ("essa opção não existe");
             break;
         }
         }
         
         if (alunoEncontrado == 1) break;
     }
     if(alunoEncontrado != 1){
        printf("Aluno não foi encontrado!\n");
     }
     
     break;
     
    case 3: 
     
     printf("Pesquisar se o aluno ja esta cadastrado\n");
     
     // Se não tiver alunos cadastrados é exibido um erro
    if(alunosCadastrados.size() == 0) {
        printf("Nenhum aluno cadastrado!\n");
        break;
    }
    printf("Digite o codigo acadêmico do aluno\n");
    scanf("%d", &codigopesquisado);
    
    int alunoFoiEncontrado;
    alunoFoiEncontrado = 0; // Inicializando com 0 (false)
    for (vector<Aluno>::iterator aluno = alunosCadastrados.begin(); aluno != alunosCadastrados.end(); aluno++) {
        if (aluno->codigoacademico == codigopesquisado) {
            alunoFoiEncontrado = 1; // coloca o valor 1 para simbolizar true (verdadeiro)
            printf("Aluno encontrado: %s.\n", aluno->nomealuno);
            printf("Esse aluno está matriculado no curso %s.\n", aluno->Cur.nomecurso);
            printf("Suas notas no semestre atual foram: \n");
            for (int i = 0; i < QUANT_DISCIPLINAS; i++) {
                // Exibe as disciplinas e cada uma das notas
                printf("Disciplina '%s':\n", aluno->Cur.Disci[i].nomedisciplina);
                 printf("Professor '%s':\n", aluno->Cur.Disci[i].nomeprofessor);
                printf("    N1: %.2f\n", aluno->Cur.Disci[i].notas[0][0]);
                printf("    N2: %.2f\n", aluno->Cur.Disci[i].notas[0][1]);
                printf("    APS: %.2f\n\n", aluno->Cur.Disci[i].notas[1][0]);
                printf(" A media é : %.2f\n",aluno->Cur.Disci[i].notas[1][1]);
            }
        }
        if (alunoFoiEncontrado == 1) break;
    }
    
    if (alunoFoiEncontrado != 1) {
        // Se o aluno não foi encontra exibe um erro
        printf("Não foi encontrado um aluno com o Código Acedêmico %d.\n", codigopesquisado);
    }
    
     break; 
     
    case 4:
     
     printf("Deletar Cadastro do aluno\n");
     
     // se o aluno nao tiver cadastrado vai erro
     if(alunosCadastrados.size() == 0) {
         printf("Nenhum aluno cadastrado!\n");
        break;
     }
     
     printf("Digite o codigo acadêmico pesquisado do aluno\n");
     scanf("%d", &codigopesquisado);
     
     int alunoencontrado;
     alunoencontrado = 0; // Inicializando com 0 (false)
     struct Aluno alunoPesquisado;
     for (vector<Aluno>::iterator aluno = alunosCadastrados.begin(); aluno != alunosCadastrados.end(); aluno++){
         if(aluno->codigoacademico == codigopesquisado){
            alunoencontrado = 1; // o numero 1 simboliza o true que seria (verdadeiro)
            printf("o aluno foi encontrado : %s\n", aluno->nomealuno);
            printf("Deseja realmente excluir esse aluno?");
         
            int menu;
            // menu de opções 
            printf("\n1 - Sim \n");
            printf("2 - Não \n ");
            printf("Escolha uma opção: \n");
            scanf("%d",&menu);
         
            switch(menu){
                case 1 :
                    printf("Deletar aluno\n");
                    printf("o aluno %s foi deletado do curso %s com sucesso!\n", aluno->nomealuno, aluno->Cur.nomecurso);
                    alunosCadastrados.erase(aluno);
                    break;
                  
                case 2 :
                    printf("Exclusão cancelada\n");
                    break;
            }
        }
        if (alunoencontrado == 1) break;
     }
     
     if(alunoencontrado != 1){
        printf("Aluno não foi encontrado!\n");
     }
     
     
     break;
     
     case 5:
     
     printf("Sair do programa \n");
     break;
     
    default:
     printf("Não tem essa opção!\n");
     break;
    }
    
    }
   while(opcao != 5);
}

// Criando os cursos pré-definidos com suas respectivas disciplinas
void init(struct Curso cursos_disponiveis[QUANT_CURSOS]) {
    strcpy(cursos_disponiveis[0].nomecurso, "Ciência da Computação");
    cursos_disponiveis[0].duracao = 2;
    strcpy(cursos_disponiveis[0].Disci[0].nomedisciplina, "Álgebra Linear\n");
    strcpy(cursos_disponiveis[0].Disci[0].nomeprofessor, "Fernando Miguel\n");
    
    strcpy(cursos_disponiveis[0].Disci[1].nomedisciplina, "Probabilidade e Estatística\n");
    strcpy(cursos_disponiveis[0].Disci[1].nomeprofessor, "Lorival Guedes\n");
    
    strcpy(cursos_disponiveis[0].Disci[2].nomedisciplina, "Banco de Dados\n");
    strcpy(cursos_disponiveis[0].Disci[2].nomeprofessor, "Pedro Ferroso\n");
    
    strcpy(cursos_disponiveis[0].Disci[3].nomedisciplina, "Redes de Computadores\n");
    strcpy(cursos_disponiveis[0].Disci[3].nomeprofessor, "Gustavo Albuquerque\n");
    
    strcpy(cursos_disponiveis[0].Disci[4].nomedisciplina, "Inteligência Artificial\n");
    strcpy(cursos_disponiveis[0].Disci[4].nomeprofessor, "Juliano Ramos\n");
    
    strcpy(cursos_disponiveis[0].Disci[5].nomedisciplina, "Análise e Desenvolvimento de Sistemas\n");
    strcpy(cursos_disponiveis[0].Disci[5].nomeprofessor, "Ricardo Reis Lopes\n");
    
    strcpy(cursos_disponiveis[0].Disci[6].nomedisciplina, "Sistemas operacionais\n");
    strcpy(cursos_disponiveis[0].Disci[6].nomeprofessor, " Vagner Feitosa\n");
    
    strcpy(cursos_disponiveis[0].Disci[7].nomedisciplina, "Empreendedorismo\n");
    strcpy(cursos_disponiveis[0].Disci[7].nomeprofessor,  "Jefferson Stenico\n");
    
    strcpy(cursos_disponiveis[1].nomecurso, "Sistemas de Informação");
    cursos_disponiveis[1].duracao = 3;
    strcpy(cursos_disponiveis[1].Disci[0].nomedisciplina, "Análise e Projeto de Sistemas\n");
    strcpy(cursos_disponiveis[1].Disci[0].nomeprofessor, " João Santos\n ");
    
    strcpy(cursos_disponiveis[1].Disci[1].nomedisciplina, "Arquitetura e Organização de Computadores\n");
    strcpy(cursos_disponiveis[1].Disci[1].nomeprofessor, " Octavio Damasco\n");
    
    strcpy(cursos_disponiveis[1].Disci[2].nomedisciplina, "Ciência de Dados\n");
    strcpy(cursos_disponiveis[1].Disci[2].nomeprofessor, " Maria Cristina\n ");
    
    strcpy(cursos_disponiveis[1].Disci[3].nomedisciplina, "Desenvolvimento web\n");
    strcpy(cursos_disponiveis[1].Disci[3].nomeprofessor, " Tiago Silva Dos Santos\n ");
    
    strcpy(cursos_disponiveis[1].Disci[4].nomedisciplina, "Algoritmos\n");
    strcpy(cursos_disponiveis[1].Disci[4].nomeprofessor, " Paulo Darossi\n ");
    
    strcpy(cursos_disponiveis[1].Disci[5].nomedisciplina, "Estrutura de Dados\n");
    strcpy(cursos_disponiveis[1].Disci[5].nomeprofessor, " Daives Bergamascco\n");
    
    strcpy(cursos_disponiveis[1].Disci[6].nomedisciplina, "Marketing Digital\n");
    strcpy(cursos_disponiveis[1].Disci[6].nomeprofessor, "Diego Bachega\n");
    
    strcpy(cursos_disponiveis[1].Disci[7].nomedisciplina, "Engenharia de Software\n");
    strcpy(cursos_disponiveis[1].Disci[7].nomeprofessor, " Rafael Guedes\n ");
    
    strcpy(cursos_disponiveis[2].nomecurso, "Segurança da Informação");
    cursos_disponiveis[2].duracao = 3;
    strcpy(cursos_disponiveis[2].Disci[1].nomedisciplina, "Matemática discreta\n");
    strcpy(cursos_disponiveis[2].Disci[1].nomeprofessor, " Romildo Vieira\n ");
    
    strcpy(cursos_disponiveis[2].Disci[2].nomedisciplina, "Criptografia\n");
    strcpy(cursos_disponiveis[2].Disci[2].nomeprofessor, "André Miazawa\n");
    
    strcpy(cursos_disponiveis[2].Disci[3].nomedisciplina, "Defesa cibernética\n");
    strcpy(cursos_disponiveis[2].Disci[3].nomeprofessor, " Marco Antônio\n");
    
    strcpy(cursos_disponiveis[2].Disci[0].nomedisciplina, "Hacking ético\n");
    strcpy(cursos_disponiveis[2].Disci[0].nomeprofessor, " Fabiano Costa\n");
    
    strcpy(cursos_disponiveis[2].Disci[4].nomedisciplina, "Algoritmos\n");
    strcpy(cursos_disponiveis[2].Disci[4].nomeprofessor, " José Almeidan\n");
    
    strcpy(cursos_disponiveis[2].Disci[5].nomedisciplina, "Estrutura de Dados\n");
    strcpy(cursos_disponiveis[2].Disci[5].nomeprofessor, " Daives Bergamascco\n");
    
    strcpy(cursos_disponiveis[2].Disci[6].nomedisciplina, "Redes de Computadores\n");
    strcpy(cursos_disponiveis[2].Disci[6].nomeprofessor, " Miguel Figueiredo\n");
    
    strcpy(cursos_disponiveis[2].Disci[7].nomedisciplina, "Cybersecurity\n");
    strcpy(cursos_disponiveis[2].Disci[7].nomeprofessor, " Vitor Silvan\n");
    
    
    strcpy(cursos_disponiveis[3].nomecurso, "Engenharia da Computação");
    cursos_disponiveis[3].duracao = 5;
    strcpy(cursos_disponiveis[3].Disci[1].nomedisciplina, "Desenvolvimento web\n");
    strcpy(cursos_disponiveis[3].Disci[1].nomeprofessor, " Antônio Rocha\n ");
    
    strcpy(cursos_disponiveis[3].Disci[2].nomedisciplina, "Desenvolvimento de games\n");
    strcpy(cursos_disponiveis[3].Disci[2].nomeprofessor, " Eder Lopes\n");
    
    strcpy(cursos_disponiveis[3].Disci[3].nomedisciplina, "Cálculo I\n");
    strcpy(cursos_disponiveis[3].Disci[3].nomeprofessor, " Wanderley Damasceno\n");
    
    strcpy(cursos_disponiveis[3].Disci[0].nomedisciplina, "Cálculo II\n");
    strcpy(cursos_disponiveis[3].Disci[0].nomeprofessor, " Wanderley Damasceno\n");
    
    strcpy(cursos_disponiveis[3].Disci[4].nomedisciplina, "Cálculo III\n");
    strcpy(cursos_disponiveis[3].Disci[4].nomeprofessor, " Wanderley Damasceno\n");
    
    strcpy(cursos_disponiveis[3].Disci[5].nomedisciplina, "Hardware\n");
    strcpy(cursos_disponiveis[3].Disci[5].nomeprofessor, " Hugo Da Costa\n ");
    
    strcpy(cursos_disponiveis[3].Disci[6].nomedisciplina, "Engenharia de Software\n");
    strcpy(cursos_disponiveis[3].Disci[6].nomeprofessor, " Davi Brito\n");
    
    strcpy(cursos_disponiveis[3].Disci[7].nomedisciplina, "Álgebra Linear\n");
    strcpy(cursos_disponiveis[3].Disci[7].nomeprofessor, " Gabriel Torres\n");
    
    
    strcpy(cursos_disponiveis[4].nomecurso, "Administração");
    cursos_disponiveis[4].duracao = 5;
    strcpy(cursos_disponiveis[4].Disci[1].nomedisciplina, "Economia aplicada à Administração\n");
    strcpy(cursos_disponiveis[4].Disci[1].nomeprofessor, " Elias Evangelista\n");
    
    strcpy(cursos_disponiveis[4].Disci[2].nomedisciplina, "Matemática Financeira\n");
    strcpy(cursos_disponiveis[4].Disci[2].nomeprofessor, " Carla Souza\n");
    
    strcpy(cursos_disponiveis[4].Disci[3].nomedisciplina, "Gestão de Custos");
    strcpy(cursos_disponiveis[4].Disci[3].nomeprofessor, " Jonas Rafael\n");
    
    strcpy(cursos_disponiveis[4].Disci[0].nomedisciplina, "Gestão da Produção\n");
    strcpy(cursos_disponiveis[4].Disci[0].nomeprofessor, " Ronaldo Uliani\n");
    
    strcpy(cursos_disponiveis[4].Disci[4].nomedisciplina, "Gestão da Inovação e Mudanças\n");
    strcpy(cursos_disponiveis[4].Disci[4].nomeprofessor, " Pedro Spaca\n");
    
    strcpy(cursos_disponiveis[4].Disci[5].nomedisciplina, "Business Inteligence\n");
    strcpy(cursos_disponiveis[4].Disci[5].nomeprofessor, " Elena Raquel\n");
    
    strcpy(cursos_disponiveis[4].Disci[6].nomedisciplina, "Pesquisa operacional\n");
    strcpy(cursos_disponiveis[4].Disci[6].nomeprofessor, " Tanara Oliveira\n");
    
    strcpy(cursos_disponiveis[4].Disci[7].nomedisciplina, "Gestão de Pessoas\n");
    strcpy(cursos_disponiveis[4].Disci[7].nomeprofessor, " Paulo de Tarso\n");
    
    
    strcpy(cursos_disponiveis[5].nomecurso, "Engenharia Civil");
    cursos_disponiveis[5].duracao = 3;
    strcpy(cursos_disponiveis[5].Disci[1].nomedisciplina, "Calculo I\n");
    strcpy(cursos_disponiveis[5].Disci[1].nomeprofessor, " Felipe Santos\n");
    
    strcpy(cursos_disponiveis[5].Disci[2].nomedisciplina, "Física I\n");
    strcpy(cursos_disponiveis[5].Disci[2].nomeprofessor, " Fabiana Logaço\n");
    
    strcpy(cursos_disponiveis[5].Disci[3].nomedisciplina, "Geometria Analítica\n");
    strcpy(cursos_disponiveis[1].Disci[3].nomeprofessor, " Roberto Queiroz\n ");
    
    strcpy(cursos_disponiveis[5].Disci[0].nomedisciplina, "Mecânica dos Sólidos\n");
    strcpy(cursos_disponiveis[5].Disci[0].nomeprofessor, "Matheus Mendes\n ");
    
    strcpy(cursos_disponiveis[5].Disci[4].nomedisciplina, "Mecânica dos Fluidos\n");
    strcpy(cursos_disponiveis[5].Disci[4].nomeprofessor, " Lucas Oliveira\n");
    
    strcpy(cursos_disponiveis[5].Disci[5].nomedisciplina, "Computação para Engenharia\n");
    strcpy(cursos_disponiveis[5].Disci[5].nomeprofessor, " Riquelme Garza\n");
    
    strcpy(cursos_disponiveis[5].Disci[6].nomedisciplina, "Topografia e Cartografia\n");
    strcpy(cursos_disponiveis[5].Disci[6].nomeprofessor, " Adela Rocha\n ");
    
    strcpy(cursos_disponiveis[5].Disci[7].nomedisciplina, "Materiais Básicos de Construção Civil\n");
    strcpy(cursos_disponiveis[5].Disci[7].nomeprofessor, " Rogério Fabuloso\n");
    
    
    strcpy(cursos_disponiveis[6].nomecurso, "Engenharia de Software");
     cursos_disponiveis[6].duracao = 2;
    strcpy(cursos_disponiveis[6].Disci[1].nomedisciplina, "Gestão da Qualidade\n");
    strcpy(cursos_disponiveis[6].Disci[1].nomeprofessor, " Yago Oliveira\n");
    
    strcpy(cursos_disponiveis[6].Disci[2].nomedisciplina, "Gerenciamento de Projetos\n");
    strcpy(cursos_disponiveis[6].Disci[2].nomeprofessor, " Suzane Cardoso\n");
    
    strcpy(cursos_disponiveis[6].Disci[3].nomedisciplina, "Inteligência Artificial Aplicada\n");
    strcpy(cursos_disponiveis[6].Disci[3].nomeprofessor, " Jhon Wesley\n");
    
    strcpy(cursos_disponiveis[6].Disci[0].nomedisciplina, "Controle Avançado de Sistemas\n");
    strcpy(cursos_disponiveis[6].Disci[0].nomeprofessor, " Pedro Helisson\n");
    
    strcpy(cursos_disponiveis[6].Disci[4].nomedisciplina, "Sistemas Digitais\n");
    strcpy(cursos_disponiveis[6].Disci[4].nomeprofessor, " Stefany Chagas\n");
    
    strcpy(cursos_disponiveis[6].Disci[5].nomedisciplina, "Sistemas Distribuídos\n");
    strcpy(cursos_disponiveis[6].Disci[5].nomeprofessor, " Larissa Santos\n ");
    
    strcpy(cursos_disponiveis[6].Disci[6].nomedisciplina, "Programação Orientada a Objetos\n");
    strcpy(cursos_disponiveis[6].Disci[6].nomeprofessor, " Luana Rosa\n");
    
    strcpy(cursos_disponiveis[6].Disci[7].nomedisciplina, "Programação Mobile\n");
    strcpy(cursos_disponiveis[6].Disci[7].nomeprofessor, "Elon Musk\n");
    
}
