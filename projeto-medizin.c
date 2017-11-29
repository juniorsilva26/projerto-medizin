/*Projeto*/

                    /* ************** BIBLIOTECAS ************** */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


                    /* ************* CONSTANTES ************** */
#define TX 100
#define XT 15
#define JK 25

                    /* ************* TECLAS *************** */
#define BACKSPACE 8
#define TAB 9
#define ENTER 13
#define ESC 27
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

                    /* ************** CORES ************** */
#define BLACK 0
#define DARKBLUE 1
#define DARKGREEN 2
#define DARKRED 4
#define DARKPINK 5
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define GREEN 10
#define BLUE 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15

                    /* ******** ENDEREÇOS DE ARQUIVOS ********* */
#define arqCliente "cadCliente.dat"
#define arqMedico "cadMedico.dat"
#define arqMedicamentos "medicamentos.dat"
#define arqConsultas "consultas.dat"
#define ARQ_AUX "auxiliar.dat"
#define auxConsultas "auxConsultas.dat"

                    /* ************** STRUCTS ************** */

struct cadastroCliente{
	char nome[30];
	char sobrenome[30];
	char email[30];
	char cpf[12];
	char nascimento[11];
    char sx[15];
    char senha[15];
    char pln[30];

}cc;

struct cadastroMedico{
	char nome[30];
	char sobrenome[30];
	char email[30];
	char cpf[12];
	char nascimento[11];
	char sx[15];
	char crm[14];
	char senha[10];
	char espc[40];
}cm;

struct consultas{
    char email[30];
    char nome[30];
    char medico[15];
    char data[14];
    char hora[6];
    char frmpg[15];
    int status;
    int ID;
}cons;

struct medicamento {
	char nome[60];
	int registro;
	float preco;
	int qtde;
};

                    /* ************** INTERFACE ************** */
                                /* *** CURSORES *** */

void gotoxy(int x, int y){
	COORD coord; coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor (int COLOR){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= COLOR);
}

void textbackground (int COLOR){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (COLOR << 4));
}

void wait(){ //Congela a tela
	int i;
	for (i = 1; i < 2; i++){
		Sleep(1);
		fflush(stdout);
    }
}

                    /* ******* PROTÓTIPOS ******* */
void admlog(); 
void arquivoMedicamentos();
void bordaext(int);
void bordaesp();
void bordaperfil();
void bordacliente(int);
int cursorperfilcliente();
int cursorperfilmed();
void cursoradm();
void consultasclient();
void adicionarMedicamentos();
void pesquisarMedicamentos();
void alterarMedicamentos();
void listarMedicamentos();
void excluirMedicamentos();
void bordalogo(int,int,int);
void logo(int,int,int);
void listarcaixa();
void listarmedicos();
void pesquisa();
void opcaodelogin(int *);
void titulo(char[],int);
void sairMedizin();
void CriarCaixinha(int x, int y1, int y2, int y3, int TamL , char texto[]);
void pesquisarMedicamentosCl(char *);
void sairMedizin();
int cursoresp(int , int);
int cursormenu(int , int );
int cursorcad(int , int );
char lersenha(int , int , char []);
int validarCPF(char []);
void lercpf_Cliente();
void lercpf_Medico();
int verificastr (char *, int , int );
void listarcaixax(int , int );
void bordaint(int );
void infoproduto();
void comprar(char [],float );
void end();
void carregando();
void pesquisarMedicamentosCl (char *);
int medicamentos();
void plnds();
void novaconsulta();
void excluirconsulta();
void nullCons();
void confCons();
void consultasmed();
void alterarCliente();
void perfilcliente();
void alterarMedico();
void perfilmed();
int segclient();
int cadclient();
int loginmed(int *);
int logincliente(int *);
void especialidade();
void segmed();
int cadmed();
void opcadastro();
void opcaodelogin(int *);
void criaArquivos(void);

void sairMedizin(){
    char tecla;
    int aux = 61, seleciona;
    system("cls");
    textcolor(BLUE);
    bordaext(BLUE);
    CriarCaixinha(42, 12, 13, 14, 30, "      DESEJA MESMO SAIR?      ");

    CriarCaixinha(42, 15, 16, 17, 13, "     SIM     ");
    textcolor(GREEN);
    CriarCaixinha(59, 15, 16, 17, 13, "     NAO     ");
    gotoxy(aux, 16);
    printf("%c", 175);


    while(seleciona != ENTER){
        char tecla = getch();
        switch(tecla){
            case RIGHT :
                if(aux < 61){
                    textcolor(BLUE);
                    CriarCaixinha(42, 15, 16, 17, 13, "     SIM     ");
                    textcolor(GREEN);
                    CriarCaixinha(59, 15, 16, 17, 13, "     NAO     ");

                    aux += 17;
                    gotoxy(aux, 16);
                    printf("%c", 175);
                }
                break;
            case LEFT :
                if (aux > 44){
                    textcolor(BLUE);
                    CriarCaixinha(59, 15, 16, 17, 13, "     NAO     ");
                    textcolor(RED);
                    CriarCaixinha(42, 15, 16, 17, 13, "     SIM     ");

                    aux -= 17;
                    gotoxy(aux, 16);
                    printf("%c", 175);
                }
                break;
            case ENTER :
                if(aux == 44){
                    exit(0);
                } else {
                    return;
                }
                break;
        }
    }
}

int cursoresp(int x, int y){
    int i = 1;
    int aux = 0;
    char type[4], senha[6];

	volta:
	textcolor(WHITE);
    gotoxy(x,y);
    printf("%c",175);
    while(i != ENTER){
            char tecla = getch();
            aux = y;
            int a = 0;
            switch(tecla){
                case DOWN:
                    y+= 3;
                    if(y == 10 || y == 13 || y == 16){
                        gotoxy(x,aux);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        y-=3;
                    }
                    break;

                case UP:
                    y-=3;
                    if(y == 10 || y == 13 || y == 16){
                       gotoxy(x,aux);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        y+=3;
                    }
                    break;

                case ENTER:
                    if (y == 10){
                    return 1;
                    }else{
                        if (y == 13){
                            return 2;
                        }else{
                            return 3;
                        }
                    }
                    break;
                case TAB:
                	gotoxy(71,20);
                	textcolor(DARKGRAY);
                	printf("Modo de Acesso: ");
                	gets(type);
                	if(strcmp(type,"adm") == 0 || strcmp(type,"ADM") == 0 || strcmp(type,"Adm") == 0){
                		textcolor(DARKGRAY);
                		gotoxy(71,21);
                		printf("Senha: ");
                		gets(senha);
                		if (strcmp(senha,"llgmf") == 0 || strcmp(senha,"LLGMF") == 0){
                			textcolor(GREEN);
                			gotoxy(71,22);
                			printf("Acesso autorizado");
                			Sleep(700);
                			admlog();
                			return;
						}else{
							textcolor(RED);
							gotoxy(71,22);
                			printf("Senha incorreta");
                			Sleep(700);
                			gotoxy(71,21);
                			printf("                     ");
                			gotoxy(71,22);
                			printf("                     ");
                			gotoxy(71,20);
                			printf("                     ");
                			goto volta;
						}
					}else{
                			textcolor(RED);
                			gotoxy(71,21);
                			printf("Acesso negado");
                			Sleep(700);
                			gotoxy(71,20);
                			printf("                                   ");
                			gotoxy(71,21);
                			printf("              ");
                			goto volta;
						}
                	break;
                case ESC :
                    sairMedizin();
                    return 0;
                    break;
        }
    }
}

int cursormenu(int x, int y){
    int i = 1;
    int auy = 0, aux = 0;

	textcolor(BLUE);
    gotoxy(x,y);
    printf("%c",175);
    while(i != ENTER){
        char tecla = getch();
        auy = y;
        aux = x;
        switch(tecla){
            case DOWN:
                y+= 3;
                if(y == 14 || y == 11){
                    gotoxy(aux,auy);
                    printf("  ");
                    gotoxy(x,y);
                    printf("%c",175);
                    }else{
                        y-=3;
                    }
                    break;
                case UP:
                    y-=3;
                    if(y == 14 || y == 11){
                       gotoxy(aux,auy);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        y+=3;
                    }
                    break;

				case RIGHT:
				    if(x < 67){
                        x+= 25;
                        if(x == 42 || x == 67){
                            gotoxy(aux,auy);
                            printf("  ");
                            gotoxy(x,y);
                            printf("%c",175);
                    	}else{
                        	y-=25;
                   		}
					}
                    break;
                case LEFT:
                    x-=25;
                    if(x == 42 || x == 67){
                    	gotoxy(aux,auy);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        x+=25;
                    }
                    break;
                case ENTER:
                    if (x == 42){
                    	if (y == 11){
                    		return 1;
						}else{
							if (y == 14){
								return 2;
							}
						}
					}else{
						if (x == 67){
							if (y == 11){
								return 3;
							}else{
								if(y == 14){
								return 4;
								}
							}
						}
					}
                    break;
                case ESC:
                    return 0;
                    break;
            }
    }
}

int cursorcad(int x, int y){
	int i = 1;
    int aux = 0;

    gotoxy(x,y);
    printf("%c",175);
    while(i != ENTER){
            char tecla = getch();
            aux = y;
            switch(tecla){
                case DOWN:
                    y+= 3;
                    if(y == 11 || y == 14){
                        gotoxy(x,aux);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        y-=3;
                    }
                    break;

                case UP:
                    y-=3;
                    if(y == 11 || y == 14){
                       gotoxy(x,aux);
                        printf("  ");
                        gotoxy(x,y);
                        printf("%c",175);
                    }else{
                        y+=3;
                    }
                    break;

                case ENTER:
                    if (y == 11){
                    return 1;
                    }else{
                        if (y == 14){
                            return 2;
                        }
                    break;
                case ESC:
                    return 0;
                    break;
            }
        }
    }
}

void adicionarMedicamentos(){
	FILE *pf;
    struct medicamento c;
    char nome[40], op;
    int i, ct = 2; //ct é um contador pra localizar a posição
    pf = fopen("Medicamentos.txt","rb");
    if(pf == NULL){
        printf("Erro no arquivo\n");
        return;
    }

    bordaext(DARKGRAY);
    titulo("ADICIONAR MEDICAMENTO",DARKGRAY);
    bordaesp();
    gotoxy(28,9);
    printf("MEDICAMENTO: ");
    textcolor(WHITE);
    gets(nome);
    fflush (stdin);
    while(fread(&c,sizeof(struct medicamento),1,pf) == 1){
        if(strcmp(nome,c.nome) == 0){
        	system("cls");
        	bordaext(RED);
        	textcolor(RED);
        	gotoxy(40,12);
        	printf("Medicamento j%c existente!",160);
            gotoxy(35,13);
            textcolor(WHITE);
            printf("Deseja entrar com outro medicamento?");
            gotoxy(43,15);
            textbackground(DARKGREEN);
            printf(" SIM ");
            textbackground(BLACK);
            gotoxy(55,15);
            printf(" N%cO ",199);
            textbackground(BLACK);
            while (1){
            	op = getch();
            	switch(op){
            		case RIGHT:
            			gotoxy(43,15);
            			textbackground(BLACK);
            			printf(" SIM ");
            			gotoxy(55,15);
            			textbackground(DARKRED);
            			printf(" N%cO ",199);
            			textbackground(BLACK);
            			ct = 1;
            			break;
            		case LEFT:
						ct = 2;
            			gotoxy(43,15);
            			textbackground(DARKGREEN);
            			printf(" SIM ");
            			gotoxy(55,15);
            			textbackground(BLACK);
            			printf(" N%cO ",199);
            			textbackground(BLACK);
            			break;
            		case ENTER:
            			if (ct == 2){
            				fclose(pf);
            				system("cls");
                			adicionarMedicamentos();
						}else{
							fclose(pf);
                			system ("cls");
                			admlog();
						}
						break;
				}
			}
        }
    }
    fclose(pf);
	fflush (stdin);
    pf = fopen("Medicamentos.txt","ab");
    if(pf == NULL){
        printf("Erro no arquivo\n");
        op = getch();
        fclose(pf);
        exit(0);
    }
    strcpy(c.nome,nome);
    textcolor(DARKGRAY);
    gotoxy(28,10);
    printf("REGISTRO: ");
    textcolor(WHITE);
    scanf("%d",&c.registro);
    fflush (stdin);

	textcolor(DARKGRAY);
	gotoxy(28,11);
    printf ("PRE%cO: ",128);
    textcolor(WHITE);
    scanf ("%f", &c.preco);
    fflush (stdin);

	textcolor(DARKGRAY);
	gotoxy(28,12);
    printf ("QUANTIDADE: ");
    textcolor(WHITE);
    scanf ("%d",&c.qtde);
    fflush(stdin);

    fwrite(&c,sizeof(c),1,pf);

    system("cls");
    bordaext(GREEN);
    textcolor(GREEN);
    gotoxy(40,12);
    printf("MEDICAMENTO REGISTRADO!",160);
    gotoxy(35,13);
    textcolor(WHITE);
    printf("Deseja entrar com outro medicamento?");
    gotoxy(43,15);
    textbackground(DARKGREEN);
    printf(" SIM ");
    textbackground(BLACK);
    gotoxy(55,15);
    printf(" N%cO ",199);
    textbackground(BLACK);
    ct = 2;
    while (1){
        op = getch();
        switch(op){
            case RIGHT:
            	gotoxy(43,15);
            	textbackground(BLACK);
            	printf(" SIM ");
            	gotoxy(55,15);
            	textbackground(DARKRED);
            	printf(" N%cO ",199);
            	textbackground(BLACK);
            	ct = 1;
            	break;
            case LEFT:
				ct = 2;
            	gotoxy(43,15);
            	textbackground(DARKGREEN);
            	printf(" SIM ");
            	gotoxy(55,15);
            	textbackground(BLACK);
            	printf(" N%cO ",199);
            	textbackground(BLACK);
            	break;
        	case ENTER:
            	if (ct == 2){
            		fclose(pf);
            		system("cls");
                	adicionarMedicamentos();
				}else{
					fclose(pf);
                	system ("cls");
                	admlog();
					}
				break;
		}
	}
}

void pesquisarMedicamentos(){
	FILE *pf;
    system("cls");
    struct medicamento c;
    char nome[40], op;

    pf = fopen("Medicamentos.txt","rb");
    if(pf == NULL){
        printf("Erro no arquivo...");
        op = getch();
        fclose(pf);
        cursoradm();
    }

	bordaext(DARKGRAY);
	titulo("PESQUISAR MEDICAMENTOS",DARKGRAY);
	pesquisa(10,6);
	gotoxy(12,7);
    printf("NOME: ");
    textcolor(WHITE);
    gets(nome);

    while(fread(&c,sizeof(struct medicamento),1,pf)==1){
        if(strcmp(nome,c.nome)==0){
        	system("cls");
        	textcolor(DARKGRAY);
        	bordaext(DARKGRAY);
        	bordaesp();
        	titulo("",DARKGRAY);
            gotoxy(40,3);
            printf("INFORMA%c%cES DO MEDICAMENTO",128,229);
            logo(LIGHTGRAY,28,9);
            bordalogo(DARKGRAY,25,7);
            textcolor(LIGHTGRAY);
            gotoxy(51,10);
            printf("NOME: %s\n",c.nome);
            gotoxy(51,11);
            printf("REGISTRO: %d\n",c.registro);
            gotoxy(51,12);
            printf ("PRE%cO: R%c %.2f\n",128,36,c.preco);
            gotoxy(51,13);
            printf ("QUANTIDADE: %d\n\n",c.qtde);

			gotoxy(37,21);
            printf("Deseja pesquisar outro medicamento?");
            textbackground(DARKGREEN);
            textcolor(WHITE);
            gotoxy(48,23);
            printf(" SIM ");
            gotoxy(57,23);
            textbackground(BLACK);
			printf(" N%cO ",199);
			int ct = 2;
			while(1){
				op = getch();
				switch(op){
					case RIGHT:
						gotoxy(48,23);
            			textbackground(BLACK);
            			printf(" SIM ");
            			gotoxy(57,23);
            			textbackground(DARKRED);
            			printf(" N%cO ",199);
            			textbackground(BLACK);
            			ct = 1; //não
            			break;
            		case LEFT:
            			gotoxy(48,23);
            			textbackground(DARKGREEN);
            			printf(" SIM ");
            			gotoxy(57,23);
            			textbackground(BLACK);
            			printf(" N%cO ",199);
            			ct = 2; //sim
            			break;
            		case ENTER:
            			if(ct == 1){
            				fclose(pf);
            				system ("cls");
                			admlog();
						}else{
							fclose(pf);
							system("cls");
							pesquisarMedicamentos();
						}
						break;
				}
			}
        }
    }
    fclose(pf);
    system("cls");
    bordaext(RED);
    textcolor(RED);
    gotoxy(39,13);
    printf("Medicamento n%co encontrado...",198);
    textcolor(LIGHTGRAY);
    gotoxy(36,14);
    printf("Deseja pesquisar outro medicamento?\n");
    gotoxy(45,16);
    textbackground(DARKGREEN);
    textcolor(WHITE);
    printf(" SIM ");
    textbackground(BLACK);
    gotoxy(56,16);
    printf(" N%cO ",199);
    int ct = 2;
    while(1){
    	op = getch();
    	switch(op){
    		case RIGHT:
    			gotoxy(45,16);
            	textbackground(BLACK);
            	printf(" SIM ");
            	gotoxy(56,16);
            	textbackground(DARKRED);
            	printf(" N%cO ",199);
            	ct = 1; //não
            	break;
			case LEFT:
				gotoxy(45,16);
            	textbackground(DARKGREEN);
            	printf(" SIM ");
            	gotoxy(56,16);
            	textbackground(BLACK);
            	printf(" N%cO ",199);
            	ct = 2; //sim
            	break;
			case ENTER:
				if (ct == 1){
					system ("cls");
        			admlog();
				}else{
					system("cls");
					pesquisarMedicamentos();
				}
				break;
			}
		}
}

void alterarMedicamentos(){
    FILE *pf;
	struct medicamento c, copy;
    char nome[40];
    char op;
    int flag = 0;

    if(pf == NULL){
        printf("Erro no arquivo...");
        op = getch();
        fclose(pf);
        admlog();
    }

	textbackground(BLACK);
	bordaext(DARKGRAY);
	titulo("ALTERAR MEDICAMENTOS",DARKGRAY);
	pesquisa(10,6);
	textcolor(LIGHTGRAY);
	gotoxy(12,7);
    printf("NOME: ");
    textcolor(WHITE);
    gets(nome);
    fflush (stdin);
    printf ("\n");
    pf = fopen("Medicamentos.txt","rb");


	FILE *aux ;
	aux = fopen("Auxiliar.txt","wb");

    while(fread(&copy,sizeof(struct medicamento),1,pf) == 1){
        if(strcmp(copy.nome,nome) == 0){
        	c = copy;
        }
        else{
        	fwrite(&copy,sizeof(struct medicamento),1,aux);
        	flag = 1;
		}
    }
    if(flag == 1){
    	char medicamento[25]; int i;
    	system("cls");
    	bordaext(DARKGRAY);
    	bordaesp();
    	titulo("",DARKGRAY);
    	for (i = 0; i < strlen(nome); i++){
    		medicamento[i] = toupper(nome[i]);
		}
    	gotoxy(40,3);
    	printf("ALTERA%c%cES EM %s",128,229,medicamento);
    	logo(LIGHTGRAY,28,9);
    	bordalogo(DARKGRAY,25,7);

    	textcolor(LIGHTGRAY);
    	gotoxy(50,10);
    	printf("NOME: ");
    	textcolor(WHITE);
        gets(c.nome);
        gotoxy(50,11);
        textcolor(LIGHTGRAY);
        printf("REGISTRO: ");
        textcolor(WHITE);
        scanf("%d",&c.registro);
        gotoxy(50,12);
        textcolor(LIGHTGRAY);
        printf ("PRE%cO: ",128);
        textcolor(WHITE);
        scanf ("%f",&c.preco);
        gotoxy(50,13);
        textcolor(LIGHTGRAY);
        printf ("QUANTIDADE: ");
		textcolor(WHITE);
        scanf ("%d",&c.qtde);

        fwrite(&c,sizeof(struct medicamento),1,aux);
        fclose(pf);
    	fclose(aux);

	    remove("Medicamentos.txt");
        rename("Auxiliar.txt","Medicamentos.txt");
        system("cls");
	}
	else{
		printf("Medicamento nao encontrado");
		fclose(pf);
    	fclose(aux);
	}

	bordaext(DARKGRAY);
	textcolor(LIGHTGRAY);
	gotoxy(35,12);
    printf("Deseja alterar os dados de outro medicamento?");
    gotoxy(45,14);
    textbackground(DARKGREEN);
    textcolor(WHITE);
    printf(" SIM ");
    gotoxy(56,14);
    textbackground(BLACK);
    printf(" N%cO ",199);
    int ct = 2;
    while(1){
    	op = getch();
    	switch(op){
    		case RIGHT:
    			gotoxy(45,14);
    			textbackground(BLACK);
    			printf(" SIM ");
    			gotoxy(56,14);
    			textbackground(DARKRED);
    			printf(" N%cO ",199);
    			ct = 1; //não
    			break;
    		case LEFT:
    			gotoxy(45,14);
    			textbackground(DARKGREEN);
    			printf(" SIM ");
    			gotoxy(56,14);
    			textbackground(BLACK);
    			printf(" N%cO ",199);
    			ct = 2; //sim
    			break;
    		case ENTER:
    			textbackground(BLACK);
    			if(ct == 1){
    				system ("cls");
        			admlog();
				}else{
					system("cls");
					setbuf(stdin,NULL);
					alterarMedicamentos();
				}
				break;
		}
	}
}

void listarMedicamentos(){
	FILE *pf;
    struct medicamento c;
    int i,t;
    char op;

    pf = fopen("Medicamentos.txt","rb");
    if(pf == NULL){
        printf("Erro...\n");
        op = getch();
        fclose(pf);
        admlog();
    }
    system("cls");
    
    bordaext(DARKGRAY);
	titulo("LISTAR MEDICAMENTOS",DARKGRAY);
	gotoxy(10,6);
	printf("%c",218);
	for (i = 0; i < 88; i++)
		printf("%c",196);
	printf("%c",191);
	t = 7;
	for(i = 0; i < 18; i++,t++){
		gotoxy(10,t);
		printf("%c",179);	
	}
	gotoxy(10,t);
	printf("%c",192);
	for (i = 0; i < 88; i++)
		printf("%c",196);
	printf("%c",217);
	t = 7;
	for(i = 0; i < 18; i++,t++){
		gotoxy(99,t);
		printf("%c",179);	
	}
	textcolor(LIGHTGRAY);
	gotoxy(18,7);
	printf("NOME");
	gotoxy(36,7);
	printf("REGISTRO");
	gotoxy(61,7);
	printf("PRE%cO",128);
	gotoxy(83,7);
	printf("QUANTIDADE");
	gotoxy(10,8);
	textcolor(DARKGRAY);
	printf("%c",195);
	for(i = 0; i < 88; i++)
		printf("%c",196);
	printf("%c",180);
	int y = 9;
	textcolor(WHITE);
    while(fread(&c,sizeof(struct medicamento),1,pf) == 1){
    	gotoxy(12,y);
        printf("%s\n",c.nome);
        gotoxy(38,y);
        printf("%d\n",c.registro);
        gotoxy(60,y);
        printf ("R%c %.2f\n",36,c.preco);
        gotoxy(87,y);
        printf ("%d",c.qtde);
        y++;
    }
    fclose(pf);
    op = getch();

    admlog();
}

void excluirMedicamentos(){
	FILE *pf;
    struct medicamento c;
    char nome[40],op;

    textbackground(BLACK);
	bordaext(DARKGRAY);
	titulo("EXCLUIR MEDICAMENTOS",DARKGRAY);
	pesquisa(10,6);
	textcolor(LIGHTGRAY);
	gotoxy(12,7);
    printf("NOME: ");
    textcolor(WHITE);
    gotoxy(18,7);
    gets(nome);

    pf = fopen("Medicamentos.txt","rb");
    if(pf == NULL){
        printf("Erro no arquivo...\n");
        fclose(pf);
        admlog();
    }

    int flag = 0;
    while(fread(&c,sizeof(struct medicamento),1,pf)==1){
        flag = 1;
        if(strcmp(nome,c.nome)==0){

        system("cls");
        	textcolor(DARKGRAY);
        	bordaext(DARKGRAY);
        	bordaesp();
        	titulo("",DARKGRAY);
            gotoxy(40,3);
            printf("INFORMA%c%cES DO MEDICAMENTO",128,229);
            logo(LIGHTGRAY,28,9);
            bordalogo(DARKGRAY,25,7);
            textcolor(LIGHTGRAY);
            gotoxy(51,10);
            printf("NOME: %s\n",c.nome);
            gotoxy(51,11);
            printf("REGISTRO: %d\n",c.registro);
            gotoxy(51,12);
            printf ("PRE%cO: R%c %.2f\n",128,36,c.preco);
            gotoxy(51,13);
            printf ("QUANTIDADE: %d\n\n",c.qtde);

        gotoxy(50,19);
        printf("Deseja remover esse medicamento?\n");
        gotoxy(57,20);
        textbackground(DARKGREEN);
        textcolor(WHITE);
        printf(" SIM ");
        gotoxy(67,20);
        textbackground(BLACK);
        printf(" N%cO ",199);
        int ct = 2;
        char tecla;
        while(1){
            tecla = getch();
            switch (tecla) {
                case RIGHT:
    			gotoxy(57,20);
    			textbackground(BLACK);
    			printf(" SIM ");
    			gotoxy(67,20);
    			textbackground(DARKRED);
    			printf(" N%cO ",199);
    			ct = 1; //não
    			break;
    		case LEFT:
    			gotoxy(57,20);
    			textbackground(DARKGREEN);
    			printf(" SIM ");
    			gotoxy(67,20);
    			textbackground(BLACK);
    			printf(" N%cO ",199);
    			ct = 2; //sim
    			break;
    		case ENTER:
    			textbackground(BLACK);
    			if(ct == 1){
    				system ("cls");
        			admlog();
				}else{
					FILE *aux;
                    aux = fopen("Auxiliar.txt","ab");
                    rewind(pf);
                    while(fread(&c,sizeof(struct medicamento),1,pf) == 1){
                        if(strcmp(nome,c.nome)!= 0){
                            fwrite(&c,sizeof(struct medicamento),1,aux);
                        }
                    }
                    fclose(pf);
                    fclose(aux);
                    remove("Medicamentos.txt");
                    rename("Auxiliar.txt","Medicamentos.txt");

				}
				break;
            }
            break;
        }

    system("cls");

    bordaext(DARKGRAY);
	textcolor(LIGHTGRAY);
	gotoxy(38,12);
    printf("Deseja excluir outro medicamento?");
    gotoxy(45,14);
    textbackground(DARKGREEN);
    textcolor(WHITE);
    printf(" SIM ");
    gotoxy(56,14);
    textbackground(BLACK);
    printf(" N%cO ",199);
    ct = 2;
    while(1){
    	op = getch();
    	switch(op){
    		case RIGHT:
    			gotoxy(45,14);
    			textbackground(BLACK);
    			printf(" SIM ");
    			gotoxy(56,14);
    			textbackground(DARKRED);
    			printf(" N%cO ",199);
    			ct = 1; //não
    			break;
    		case LEFT:
    			gotoxy(45,14);
    			textbackground(DARKGREEN);
    			printf(" SIM ");
    			gotoxy(56,14);
    			textbackground(BLACK);
    			printf(" N%cO ",199);
    			ct = 2; //sim
    			break;
    		case ENTER:
    			textbackground(BLACK);
    			if(ct == 1){
    				system ("cls");
        			admlog();
				}else{
					system("cls");
					setbuf(stdin, NULL);
					excluirMedicamentos();
				}
				break;
		}
	}
        }
    }

    op = getch();
    if(op == '1'){
      system("cls");
      fclose(pf);
      excluirMedicamentos();
    }else{
        getch();
        system("cls");
        admlog();
    }
}

void cursoradm(){
	char i;
	int cont = 0, *op;
	textcolor(LIGHTGRAY);
	gotoxy(58,11);
	printf("ADICIONAR MEDICAMENTOS");
	gotoxy(58,13);
	printf("PESQUISAR MEDICAMENTOS");
	gotoxy(58,15);
	printf("ALTERAR MEDICAMENTOS");
	gotoxy(58,17);
	printf("LISTAR MEDICAMENTOS");
	gotoxy(58,19);
	printf("EXCLUIR MEDICAMENTOS");
	gotoxy(58, 21);
	printf ("SAIR");
	textcolor(WHITE);
	gotoxy(56,11);
	printf("%c",175);
	int y = 11, aux;
	while(i != ENTER){
		i = getch();
		switch(i){
			case DOWN:
				aux = y;
				y+= 2;
                if(y == 11 || y == 13 || y == 15 || y == 17 || y == 19 || y == 21){
                	gotoxy(56,aux);
                	printf("  ");
                    gotoxy(56,y);
                    printf("%c",175);
                    }else{
                        y-=2;
                    }
				break;
			case UP:
				aux = y;
				y-= 2;
				if(y == 11 || y == 13 || y == 15 || y == 17 || y == 19 || y == 21){
					gotoxy(56,aux);
					printf(" ");
					gotoxy(56,y);
					printf("%c",175);
				}else{
					y+= 2;
				}
				break;
			case ENTER:
				if (y == 11){ // adicionar medicamentos
					system("cls");
					adicionarMedicamentos();
				}else{
					if (y == 13){ // pesquisar
						system("cls");
						pesquisarMedicamentos();
					}else{
						if (y == 15){ //alterar
							system("cls");
							alterarMedicamentos();
						}else{
							if (y == 17){//listar
								system("cls");
								listarMedicamentos();
							}else{
								if (y == 19){ //excluir
									system("cls");
									excluirMedicamentos();
								}
								else{
									if (y == 21){ //sair
										system ("cls");
										return;
									}
								}
							}
						}
					}
				}
		}
	}

}

char lersenha(int x, int y, char senha[]){
	int i = 0;
    char c;
    voltsenha:
    	gotoxy(x,y);
   		do{
            c = getch();
            if(isprint(c)) {    //Analisa se o valor da variável c é imprimivel
                senha[i] = c;
                i++;
                printf("*");
            }else
                if(c == BACKSPACE && i > 0) {
                    senha[i] = '\0';
                    i--;
                    printf("\b \b");
                }
        }while(c != ENTER);

    senha[i] = '\0';
    setbuf(stdin, NULL);

    if(strlen(senha) == 0){
        gotoxy(x,y);
        printf("Campo obrigatorio!");
        Sleep(1000);
        gotoxy(x,y);
        printf("                              ");
        goto voltsenha;
    }

}

                   				 /* *** VALIDADORES *** */
//			Nessa parte fica as funções que verificam se todos os campos foram preenchidos, etc.

int validarCPF(char cpf[]){ //Verifica se o CPF é valido
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

void lercpf_Cliente(){ //Leitura do CPF
    struct cadastroCliente verConta;
	int confirmacpf = 0;
	while(confirmacpf != 1){ //Verificação do CPF
		cpf:
		gotoxy(33,13);
 		printf("                                               ");
		textcolor(WHITE);
		setbuf(stdin,NULL);
    	gotoxy(33,13);
            gets(cc.cpf);
            FILE *arq = fopen(arqCliente, "rb");
            while(!feof(arq)){
                fread(&verConta, sizeof(struct cadastroCliente), 1, arq);
                if(!strcmp(verConta.cpf, cc.cpf)){
                    fclose(arq);
                    textcolor(RED);
                    gotoxy(33,13);
                    printf("CPF j%c registrado!", 160);
                    Sleep(1000);
                    setbuf(stdin,NULL);
                    goto cpf;
                }

            }
            if(!strcmp(cc.cpf, "0")){
                fclose(arq);
                confirmacpf = 1;
            }
            else{
                confirmacpf = validarCPF(cc.cpf);
                if(confirmacpf == 0){
                    gotoxy(33,13);
                    printf("\t\t\t\t");
                    textcolor(LIGHTGRAY);
                    gotoxy(33,13);
                    printf("Inv%clido, tente novamente",160);
                    setbuf(stdin,NULL);
                    getch();
                    goto cpf;
                    }else{
                        textcolor(LIGHTGRAY);
                        gotoxy(54,13);
                        printf("V%clido",160);
                        setbuf(stdin,NULL);
                        wait();
                    }
            }
        }
        setbuf(stdin,NULL);
}

void lercpf_Medico(){ //Leitura do CPF
    struct cadastroCliente verConta;
	int confirmacpf = 0;
	while(confirmacpf != 1){ //Verificação do CPF
		cpf:
		gotoxy(33,13);
 		printf("                                               ");
		textcolor(WHITE);
		setbuf(stdin,NULL);
    	gotoxy(33,13);
            gets(cm.cpf);
            FILE *arq = fopen(arqMedico, "rb");
            while(!feof(arq)){
                fread(&verConta, sizeof(struct cadastroCliente), 1, arq);
                if(!strcmp(verConta.cpf, cm.cpf)){
                    fclose(arq);
                    textcolor(RED);
                    gotoxy(33,13);
                    printf("CPF j%c registrado!", 160);
                    Sleep(1000);
                    setbuf(stdin,NULL);
                    goto cpf;
                }

            }
            if(!strcmp(cm.cpf, "0")){
                fclose(arq);
                confirmacpf = 1;
            }
            else{
                confirmacpf = validarCPF(cm.cpf);
                if(confirmacpf == 0){
                    gotoxy(33,13);
                    printf("\t\t\t\t");
                    textcolor(LIGHTGRAY);
                    gotoxy(33,13);
                    printf("Inv%clido, tente novamente",160);
                    getch();
                    goto cpf;
                    }else{
                        textcolor(LIGHTGRAY);
                        gotoxy(54,13);
                        printf("V%clido",160);
                        wait();
                    }
            }
        }
        setbuf(stdin,NULL);
}

int verificastr (char *string, int x, int y){
	gets(string);
    if (strlen(string) == 0 ){
    	gotoxy(x,y);
        printf("Campo Obrigat%crio",162);
        Sleep(1000);
        gotoxy(x,y);
        printf("                 ");
        return -1;
    }else{
    	return 0;
	}
}

                                /* *** TEMPLATE *** */

void CriarCaixinha(int x, int y1, int y2, int y3, int TamL ,char texto[]){
    int i;
	gotoxy(x,y1);
    printf("%c",201);
    for (i = 0; i < TamL; i++){
        printf("%c",205);
    }
    printf("%c\n",187);
    gotoxy(x,y2);
    printf("%c",186);
    printf("\%s",texto);
    printf("%c\n", 186);
    gotoxy(x,y3);
    printf("%c", 200);
    for (i = 0; i < TamL; i++){
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void titulo(char str[],int COLOR){
	int i, x = 6;
	gotoxy(5,4);
	printf("%c",204);
	for (i = 0; i < 100; i++,x++){
		gotoxy(x,4);
		printf("%c",205);
	}
	gotoxy(106,4);
	printf("%c",185);
	gotoxy(48,3);
	puts(str);
	gotoxy(103,3);

	textcolor(WHITE);
	printf("X");
	textcolor(COLOR);
	gotoxy(100,2);
	printf("%c",203);
	gotoxy(100,3);
	printf("%c",186);
	gotoxy(100,4);
	printf("%c",202);
}

void bordaext(int COLOR){
    int i, j = 3;
    textcolor(COLOR);
    gotoxy(5,2); //borda superior
    printf("%c",201);
    for (i = 0; i < TX; i++){
        printf("%c",205);
    }
    printf("%c\n",187);

    for (i = 0; i < JK; i++){ //bordas verticais
    	gotoxy(5,j);
        printf("%c",186);
        gotoxy(106,j);
        printf("%c\n",186);
        j++;
    }

    gotoxy(5,27); //borda inferior
    printf("%c",200);
    for (i = 0; i < TX; i++){
        printf("%c",205);
    }
    printf("%c",188);
}

void bordacliente(int COLOR){
	int i;

	textcolor(COLOR);

	//barra de ferramentas
	gotoxy(5,25);
	printf("%c",204);
	for (i = 0; i < 85; i++){
		printf("%c",205);
	}
	if (!strcmp(cm.crm, "0")){
		gotoxy(7,26);
		printf("Cliente: %s %s",cc.nome,cc.sobrenome);
	}else{
		if (cm.crm != 0){
			gotoxy(7,26);
			printf("Dr. %s %s",cm.nome,cm.sobrenome);
		}
	}


    //imprime data e hora
    char dateStr[9];
	char timeStr[6];
    gotoxy(84,26);
    printf("%s",__DATE__);
    printf(" / ");
    gotoxy(98,26);
    _strtime(timeStr);
    for (i = 0; i < 5; i++){
    	printf("%c",timeStr[i]);
	}

	//borda saida
	gotoxy(106,25);
    printf("%c",185);
    gotoxy(91,25);
    for (i = 0; i < 15; i++){
    	printf("%c",205);
	}
}

void bordaperfil(){
    int i, j = 9;
    gotoxy(25,8); //curva superior esquerda
    printf("%c",201);
    for (i = 0; i < 60; i++){ //borda superior
        printf("%c",205);
    }
    printf("%c",187); //curva superior direita
    for (i = 12; i < 25; i++){//bordas verticais
        gotoxy(25,j);
        printf("%c",186);
        gotoxy(86,j);
        printf("%c",186);
        j++;
    }

    gotoxy(25,22); //curva inferior esquerda
    printf("%c",200);
    gotoxy(26,22); //borda inferior
    for (i = 0; i < 60; i++){
        printf("%c",205);
    }
    gotoxy(86,22);
    printf("%c",188);
}

void bordaesp(){
    int i, j = 8;
    gotoxy(25,7); //curva superior esquerda
    printf("%c",201);
    for (i = 0; i < 60; i++){ //borda superior
        printf("%c",205);
    }
    printf("%c",187); //curva superior direita
    for (i = 12; i < 21; i++){//bordas verticais
        gotoxy(25,j);
        printf("%c",186);
        gotoxy(86,j);
        printf("%c",186);
        j++;
    }

    gotoxy(25,17); //curva inferior esquerda
    printf("%c",200);
    gotoxy(26,17); //borda inferior
    for (i = 0; i < 60; i++){
        printf("%c",205);
    }
    gotoxy(86,17);
    printf("%c",188);
}

void pesquisa(int x, int y){
	int i;
	gotoxy(x,y);
	printf("%c",218);
	for (i = 0; i < 50; i++){
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(x,y+1);
	printf("%c",179);
	gotoxy(x+51,y+1);
	printf("%c",179);
	gotoxy(x,y+2);
	printf("%c",192);
	for (i = 0; i < 50; i++){
		printf("%c",196);
	}
	printf("%c",217);
	gotoxy(x+51,y);
	printf("%c",194);
	for (i = 0; i < 10; i++)
	printf("%c",196);
	printf("%c",191);
	gotoxy(x+62,y+1);
	printf("%c",179);
	gotoxy(x+62,y+2);
	printf("%c",217);
	gotoxy(x+51,y+2);
	printf("%c",193);
	for (i = 0; i < 10; i++)
	printf("%c",196);
	gotoxy(x+53,y+1);
	printf("PROCURAR");

}

void listarcaixa(int x, int y){
	int i;
	gotoxy(x,y);
	printf("%c",218);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(x,y+1);
	printf("%c",179);
	gotoxy(x+87,y+1);
	printf("%c",179);
	gotoxy(x,y+2);
	printf("%c",195);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",180);
	int t = y+3;
	for(i = 0; i < 10; i++,t++){
		gotoxy(x,t);
		printf("%c",179);
		gotoxy(x+87,t);
		printf("%c",179);
	}
	gotoxy(x,t);
	printf("%c",192);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",217);

	gotoxy(x+35,y);//tabela regist
	printf("%c",194);
	int aux = y+1;
	for(i = 0; i < 12; i++,aux++){
		gotoxy(x+35,aux);
		printf("%c",179);
	}
	gotoxy(x+35,y+2);
	printf("%c",197);

	gotoxy(x+60,y);//tabela qtde
	printf("%c",194);
	int a = y+1;
	for(i = 0; i < 12; i++,a++){
		gotoxy(x+60,a);
		printf("%c",179);
	}
	gotoxy(x+60,y+2);
	printf("%c",197);
	gotoxy(x+35,y+13);
	printf("%c",193);
	gotoxy(x+60,y+13);
	printf("%c",193);
}

void listarcaixax(int x, int y){
	int i;
	gotoxy(x,y);
	printf("%c",218);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",191);
	gotoxy(x,y+1);
	printf("%c",179);
	gotoxy(x+87,y+1);
	printf("%c",179);
	gotoxy(x,y+2);
	printf("%c",195);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",180);
	int t = y+3;
	for(i = 0; i < 10; i++,t++){
		gotoxy(x,t);
		printf("%c",179);
		gotoxy(x+87,t);
		printf("%c",179);
	}
	gotoxy(x,t);
	printf("%c",192);
	for (i = 0; i < 86; i++){
		printf("%c",196);
	}
	printf("%c",217);

	gotoxy(x+25,y);//tabela consulta
	printf("%c",194);
	int aux = y+1;
	for(i = 0; i < 12; i++,aux++){
		gotoxy(x+25,aux);
		printf("%c",179);
	}
	gotoxy(x+25,y+2);
	printf("%c",197);

	gotoxy(x+43,y);//tabela data
	printf("%c",194);
	aux = y+1;
	for(i = 0; i < 12; i++,aux++){
		gotoxy(x+43,aux);
		printf("%c",179);
	}
	gotoxy(x+43,y+2);
	printf("%c",197);


	gotoxy(x+63,y);//tabela medico
	printf("%c",194);
	int a = y+1;
	for(i = 0; i < 12; i++,a++){
		gotoxy(x+63,a);
		printf("%c",179);
	}
	gotoxy(x+63,y+2);
	printf("%c",197);
	gotoxy(x+25,y+13);
	printf("%c",193);
	gotoxy(x+43,y+13);
	printf("%c",193);
	gotoxy(x+63,y+13);
	printf("%c",193);
}

void bordalogo(int COLOR, int x, int y){
    int i;
    int j = y+1; //x = 30, y = 6
    textcolor(COLOR);
    gotoxy(x,y); //curva superior esquerda
    printf("%c",201);
    for (i = 0; i < 20; i++){ //borda superior
    	printf("%c",205);
    }
    printf("%c",187); //curva superior direita
    for (i = 12; i < 21; i++){//bordas verticais
    	gotoxy(x,j);
    	printf("%c",186);
    	gotoxy(x+21,j);
    	printf("%c",186);
    	j++;
    }

	gotoxy(x,y+10); //curva inferior esquerda
    printf("%c",200);
    gotoxy(x+1,y+10); //borda inferior
    for (i = 0; i < 20; i++){
        printf("%c",205);
    }
	printf("%c",188);
}

void bordaint(int COLOR){
    textcolor(COLOR);
    int i, j = 4;
    gotoxy(7,3); //borda superior
    printf("%c",201);
    for (i = 0; i < TX-4; i++){
        printf("%c",205);
    }
    printf("%c",187);

    for (i = 0; i < JK-2; i++){ //bordas verticais
        gotoxy(7,j);
        printf("%c",186);
        gotoxy(142,j);
        printf("%c\n",186);
        j++;
    }


    gotoxy(7,36); //borda inferior
    printf("%c",200);
    for (i = 0; i < TX-4; i++){
    printf("%c",205);
    }
    printf("%c",188);
}

void infoproduto(){
	int i;
	char x;
	gotoxy(12,8);
	printf("%c",201);
	for (i =0; i < 50; i++){
		printf("%c",205);
	}
	printf("%c",187);

	int j = 9;
	for (i = 0; i < 13; i++, j++){
		gotoxy(12,j);
		printf("%c",186);
		gotoxy(63,j);
		printf("%c",186);
	}
	gotoxy(12,21);
	printf("%c",200);
	for (i =0; i < 50; i++){
		printf("%c",205);
	}
	printf("%c",188);

	gotoxy(14,9);
	printf("PRODUTO");
	gotoxy(48,9);
	printf("VALOR");
	gotoxy(12,10);
	printf("%c",204);
	for (i = 0; i < 50; i++){
	printf("%c",205);}
	printf("%c",185);

	gotoxy(46,8);
	printf("%c",203);
	int y;
	for (y = 9; y < 21; y++){
	gotoxy(46,y);
	printf("%c",186);
	}
	gotoxy(46,10);
	printf("%c",206);
	gotoxy(46,21);
	printf("%c",202);
}

void comprar(char nome[],float preco){
	char op;
	bordaext(BLUE);
	bordacliente(BLUE);
	titulo("MEU CARRINHO",BLUE);
	infoproduto();

	CriarCaixinha(70,9,10,11,23," ADICIONAR AO CARRINHO ");
	CriarCaixinha(70,12,13,14,23,"    CANCELAR COMPRA    ");

	gotoxy(14,11);
	printf("%s",nome);
	gotoxy(48,11);
	printf("%.2f",preco);

	int qtde;
	float total = 0;

	gotoxy(68,10);
	printf("%c",175);
	int y = 10, aux;
	while(1){
		op = getch();
		switch(op){
			case DOWN:
				aux = y;
				if(y == 10){
					gotoxy(68,aux);
					printf(" ");
					y+=3;
					gotoxy(68,y);
					printf("%c",175);
				}else{
					y-=3;
				}
				break;
			case UP:
				aux = y;
				if(y == 13){
					gotoxy(68,aux);
					printf(" ");
					y-=3;
					gotoxy(68,y);
					printf("%c",175);
				}else{
					y+=3;
				}
				break;
			case ENTER:
				if (y == 10){
					system ("cls");
					bordaext(BLUE);
					titulo("FINALIZANDO COMPRA",BLUE);
					CriarCaixinha(15,7,8,9,50,"                                                  ");
					gotoxy(17,8);
					printf ("QUANTIDADE: ");
					textcolor(WHITE);
					scanf ("%d", &qtde);

					struct medicamento help;
					FILE *fp = fopen("medicamentos.txt","rb");
					while(fread(&help,sizeof(struct medicamento),1,fp) == 1){
						if(!strcmp(help.nome,nome))
							break;
					}
					if(help.qtde - qtde >= 0){
						total = preco * qtde;
						textcolor(BLUE);
						CriarCaixinha(15,10,11,12,50,"                                                  ");
						gotoxy(17,11);
						printf ("VALOR TOTAL: \t\t\t       R%c %.2f",36, total);
					}else{
						textcolor(BLUE);
						CriarCaixinha(15,10,11,12,50,"                                                  ");
						gotoxy(17,11);
						printf ("SEM ESTOQUE");
					}

					CriarCaixinha(15,14,15,16,22,"       CANCELAR       ");
					CriarCaixinha(43,14,15,16,22,"      CONFIRMAR       ");
					textcolor(LIGHTGRAY);
					gotoxy(24,18);
					textcolor(YELLOW);
					printf("[ESC] CANCELAR   [ENTER] CONFIRMAR");
					op = getch();
					if(op == ENTER){
						system("cls");
						int t = 0, i;
						do{
							i = 8;
							while(i < 16){
								bordaext(BLUE);
								textcolor(i);
    							CriarCaixinha(37,12,13,14,35,"        COMPRA FINALIZADA!         ");
    							Sleep(50);
    							i++;
							}
							t++;
						}while(t <= 3);
						system("cls");
						menu(op);
					}else{
						system("cls");
						menu(op);
					}
				}else{
					if (y == 13){
						system("cls");
						return; //volta
					}
				}
				break;
		}
	}
	system("cls");
}

void logo(int COLOR,int x, int y){
    textcolor(COLOR);
    gotoxy(x,y);
    printf("ooo        ooooo");
    gotoxy(x,y+1);
	printf("`88.       .888'");
 	gotoxy(x,y+2);
	printf(" 888b     d'888 ");
 	gotoxy(x,y+3);
	printf(" 8 Y88. .P  888");
 	gotoxy(x,y+4);
	printf(" 8  `888'   888");
 	gotoxy(x,y+5);
	printf(" 8    Y     888 ");
	gotoxy(x,y+6);
	printf("o8o        o888o");

	gotoxy(x-1,y+9);
	printf("Assist%cncia M%cdica",136,130);
	gotoxy(x+1,y+10);
	printf("M E D I Z I N");
}

void end(){
    while(1){
        system("Color 1A");
        system("Color 2B");
        system("Color 3C");
        system("Color 4D");
        system("Color 5E");
        system("Color 6F");
        system("Color A1");
        system("Color B2");
        system("Color C3");
        system("Color D4");
        system("Color E5");
        system("Color F6");
    }
}

void carregando(){ // cc christian pinheiro
    int i;
    system("cls");
    bordaext(BLUE);
    gotoxy(XT,7);
    printf("ooo        ooooo oooooooooooo oooooooooo.   ooooo  oooooooooooo ooooo ooooo      ooo\n");
    gotoxy(XT,8);
    printf("`88.       .888' `888'     `8 `888'   `Y8b  `888'          888' `888'  999.       8\n");
    gotoxy(XT,9);
    printf(" 888b     d'888   888          888      888  888        .888P    888   8 `88b.    8\n");
    gotoxy(XT,10);
    printf(" 8 Y88. .P  888   888oooo8     888      888  888       d888'     888   8   `88b.  8\n");
    gotoxy(XT,11);
    printf(" 8  `888'   888   888          888      888  888     .888        888   8     `88b.8 \n");
    gotoxy(XT,12);
    printf(" 8    Y     888   888       o  888     d88'  888    d888'    .P  888   8       `888\n");
    gotoxy(XT,13);
    printf("o8o        o888o o888ooooood8 o888bood8P'   o888o .8888888888P  o888o o8o        `8\n\n\n\n");

    gotoxy(47,19);
    printf("Carregando...");
    gotoxy(25,20);

    for(i=1;i<30;i++){
        Sleep(70); // retarda em 50 milisegundos a execução
        textcolor(BLUE);
        printf("\xDB");
        textcolor(BLACK);
        printf("|");

    }
    textcolor(BLUE);
    gotoxy(47,19);
    printf("              ");
    gotoxy(47,19);
    printf("CARREGADO!");

    system("cls");
}

                    /* ************** FUNÇÕES DO PROGRAMA ************** */

void pesquisarMedicamentosCl (char *nome){
	FILE *pf;
    system("cls");
    struct medicamento c;
    char op;

    pf = fopen("Medicamentos.txt","rb");
    if(pf == NULL){
        printf("Erro no arquivo...");
        op = getch();
        fclose(pf);
        cursoradm();
    }
	bordaext(BLUE);
	titulo("PESQUISAR MEDICAMENTOS",BLUE);
    while(fread(&c,sizeof(struct medicamento),1,pf)==1){
        if(strcmp(nome,c.nome)==0){
        	system("cls");
        	textcolor(BLUE);
        	bordaext(BLUE);
        	bordaesp();
        	titulo("",BLUE);
            gotoxy(40,3);
            printf("INFORMA%c%cES DO MEDICAMENTO",128,229);
            logo(BLUE,28,9);
            bordalogo(BLUE,25,7);
            textcolor(BLUE);
            gotoxy(51,10);
            printf("NOME: %s\n",c.nome);
            gotoxy(51,11);
            printf("REGISTRO: %d\n",c.registro);
            gotoxy(51,12);
            printf ("PRE%cO: R%c %.2f\n",128,36,c.preco);
            gotoxy(51,13);
            printf ("QUANTIDADE: %d\n\n",c.qtde);

			gotoxy(39,21);
            printf("Deseja adicionar no seu carrinho?");
            textbackground(DARKGREEN);
            textcolor(WHITE);
            gotoxy(48,23);
            printf(" SIM ");
            gotoxy(57,23);
            textbackground(BLACK);
			printf(" N%cO ",199);
			int ct = 2, *s;
			while(1){
				op = getch();
				switch(op){
					case RIGHT:
						gotoxy(48,23);
            			textbackground(BLACK);
            			printf(" SIM ");
            			gotoxy(57,23);
            			textbackground(DARKRED);
            			printf(" N%cO ",199);
            			textbackground(BLACK);
            			ct = 1; //não
            			break;
            		case LEFT:
            			gotoxy(48,23);
            			textbackground(DARKGREEN);
            			printf(" SIM ");
            			gotoxy(57,23);
            			textbackground(BLACK);
            			printf(" N%cO ",199);
            			ct = 2; //sim
            			break;
            		case ENTER:
            			if(ct == 1){
            				fclose(pf);
            				system ("cls");
                			menu(&s);
						}else{
							fclose(pf);
							system("cls");
							comprar(c.nome,c.preco);
						}
						break;
				}
            }
        }
    }
    fclose(pf);

	gotoxy(32, 14);
	textcolor(RED);
	CriarCaixinha(40, 13, 14, 15, 30, "                              ");
	gotoxy(43, 14);
	textcolor(BLUE);
    printf("MEDICAMENTO N%cO ENCONTRADO\n", 199);
    gotoxy(38, 17);
    printf("Deseja pesquisar outro medicamento?\n");
    gotoxy(40, 18);
    textbackground(DARKGREEN);
	textcolor(WHITE);
    gotoxy(48,23);
    printf(" SIM ");
    gotoxy(57,23);
    textbackground(BLACK);
	printf(" N%cO ",199);
	int ct = 2;
	while(1){
		op = getch();
			switch(op){
				case RIGHT:
					gotoxy(48,23);
           			textbackground(BLACK);
           			printf(" SIM ");
           			gotoxy(57,23);
           			textbackground(DARKRED);
           			printf(" N%cO ",199);
           			textbackground(BLACK);
           			ct = 1; //não
           			break;
            		case LEFT:
            			gotoxy(48,23);
            			textbackground(DARKGREEN);
            			printf(" SIM ");
            			gotoxy(57,23);
            			textbackground(BLACK);
            			printf(" N%cO ",199);
            			ct = 2; //sim
            			break;
            		case ENTER:
            			if(ct == 1){
            				fclose(pf);
            				system ("cls");
                			menu();
						}else{
							fclose(pf);
							system("cls");
							medicamentos();
						}
						break;
			}
		}
	}

int medicamentos(){
	int i, x = 6, *op;
	char nome[45],tc;
	bordaext(BLUE);
	bordacliente(BLUE);
	pesquisa(10,6);
	titulo("MEDICAMENTOS",BLUE);

	textcolor(WHITE);
	gotoxy(12,7);
	gets(nome);
	pesquisarMedicamentosCl(nome);

	struct medicamento c;
	FILE *pf = fopen("medicamentos.txt","rb");
	while(fread(&c,sizeof(struct medicamento),1,pf)==1){
        if(strcmp(nome,c.nome)==0){
        	listarcaixa(10,9);
			gotoxy(12,10);
			printf("NOME");
        	gotoxy(47,10);
        	printf("REGISTRO");
        	gotoxy(72,10);
        	printf("PRE%cO",128);
        	gotoxy(12,12);
            printf("%s",c.nome);
            gotoxy(47,12);
            printf("%d\n",c.registro);
            gotoxy(72,12);
            printf ("R%c %.2f\n",36,c.preco);
            textcolor(DARKGRAY);
			gotoxy(17,23);
            printf("[ENTER] ADICIONAR AO CARRINHO   [TAB] LISTAR MEDICAMENTOS   [ESC] VOLTAR");
            tc = getch();
            fclose(pf);
            if(tc == ENTER){
               system("cls");
               comprar(c.nome,c.preco);
            }else{
                if(tc == TAB){
                	//listar medicamentos
				}else{
					if(tc == ESC){
						system("cls");
						medicamentos();
					}
				}
            }
		}
    }

    fclose(pf);
    textcolor(RED);
    gotoxy(26,15);
    printf("Medicamento n%co encontrado, tente novamente mais tarde!",198);
    textcolor(DARKGRAY);
    gotoxy(17,16);
    printf("[ENTER] TENTAR NOVAMENTE  [TAB] LISTAR MEDICAMENTOS   [ESC] VOLTAR");
    tc = getch();
    if(tc == ENTER){
    	system("cls");
        medicamentos();
    }else{
        if(tc == TAB){
        	//listar medicamentos
		}else{
			if(tc == ESC){
				system("cls");
				menu();
			}
		}
    }
}

void plnds(){
	int i, x;
    bordaext(BLUE);
    bordaesp();

    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c     PLANO DE SA%cDE      %c",185,163,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",188);
    textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ENTER %c Confirmar",175,175);

	textcolor(BLUE);
	CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    gotoxy(38,10);
    printf("Cadastre-se em um de nossos planos!",163);
    gotoxy(30,11);
    printf("Obs: Verificar forma de pagamento com o contratante.", 160);

    gotoxy(41, 13);
    printf("PLANO 1 - SIMPLES  (R$: 50,00)");
    gotoxy(41, 14);
    printf("PLANO 2 - ESPECIAL (R$: 90,00)");
    gotoxy(41, 15);
    printf("N%cO CONTRATAR      (R$: 00,00)", 199);

    int aux = 13;
    char tecla;
    gotoxy(39, aux);
    printf("%c", 175);

    while(1){
        tecla = getch();
        switch (tecla){
            case DOWN :
                if(aux < 15){
                    gotoxy(39,aux);
                    printf(" ");
                    aux++;
                    gotoxy(39, aux);
                    printf("%c", 175);
                } break;
            case UP :
                if(aux > 13){
                    gotoxy(39,aux);
                    printf(" ");
                    aux--;
                    gotoxy(39, aux);
                    printf("%c", 175);
                } break;
            case ENTER :
                switch (aux){
                    case 13 :
                        strcpy(cc.pln, "PLN 1");
                        system("cls");
                        return;
                        break;
                    case 14 :
                        strcpy(cc.pln, "PLN 2");
                        system("cls");
                        return;
                        break;
                    case 15 :
                        strcpy(cc.pln, "-");
                        system("cls");
                        return;
                        break;
                }

                break;
        }
    }
}

void novaconsulta(){
    setbuf(stdin, NULL);
    FILE *arq;
    int escolha = 33;
	bordaext(BLUE);
    bordacliente(BLUE);
	titulo("NOVA CONSULTA",BLUE);
	char e, txt[] = "                                                       ";


	CriarCaixinha(20,10,11,12,24,"                        ");
	gotoxy(22,11);
	printf("DATA:");
	CriarCaixinha(51,10,11,12,24,"                        ");
	gotoxy(53,11);
	printf("HOR%cRIO:",181);
	CriarCaixinha(20,13,14,15,55,txt);
	gotoxy(22,14);
	printf("M%cDICO:",144);
	CriarCaixinha(58,16,17,18,17,"    CONTINUAR    ");

	/* Preenche os campos */
	textcolor(WHITE);
	setbuf(stdin,NULL);
	gotoxy(28,11);
	gets(cons.data);
	setbuf(stdin,NULL);
	gotoxy(62,11);
	gets(cons.hora);
	setbuf(stdin,NULL);
	textcolor(LIGHTGRAY);
	volta:
	gotoxy(30,14);
	printf("TAB para ver lista de m%cdicos",130);
	e = getch();
	switch(e){
		case ENTER:
			gotoxy(30,14);
			printf("                              ");
			goto continua;
			break;
		case TAB:
			system("cls");
			listarmedicos();
			goto continua;
			break;
		default:
			gotoxy(30,14);
			printf("                              ");
			gotoxy(30,14);
			printf("Op%c%co Inv%clida",135, 198,160);
			Sleep(800);
			gotoxy(30,14);
			printf("                   ");
			goto volta;
			break;
	}

	setbuf(stdin,NULL);

	continua:
    // recria a interface
    bordaext(BLUE);
    bordacliente(BLUE);
	titulo("NOVA CONSULTA",BLUE);

	CriarCaixinha(20,10,11,12,24,"                        ");
	gotoxy(22,11);
	printf("DATA:");
	CriarCaixinha(51,10,11,12,24,"                        ");
	gotoxy(53,11);
	printf("HOR%cRIO:",181);
	CriarCaixinha(20,13,14,15,55,txt);
	gotoxy(22,14);
	printf("M%cDICO:",144);
	CriarCaixinha(58,16,17,18,17,"    CONTINUAR    ");

    textcolor(WHITE);
	gotoxy(28,11);
	printf("%s", cons.data);
	setbuf(stdin,NULL);
	gotoxy(62,11);
	printf("%s", cons.hora);
	setbuf(stdin,NULL);
	textcolor(LIGHTGRAY);

	textcolor(WHITE);
	gotoxy(30,14);
	gets(cons.medico);
	setbuf(stdin,NULL);

	textcolor(GREEN);
	CriarCaixinha(58,16,17,18,17,"    CONTINUAR    ");

	getch();

	system("cls");
	bordaext(BLUE);
    bordacliente(BLUE);
	titulo("NOVA CONSULTA",BLUE);

    textcolor(BLUE);
	CriarCaixinha(30,10,11,12,48,"               FORMA DE PAGAMENTO               ");
	CriarCaixinha(30,13,14,15,22,"                      ");
	CriarCaixinha(56,13,14,15,22,"       DINHEIRO       ");

	gotoxy(35,14);
	printf("PLANO DE SA%CDE", 233);
	textcolor(WHITE);
	gotoxy(escolha,14);
	printf("%c", 175);

    // forma de pagamento
	do {
        e = getch();
        switch(e){
            case LEFT :
                if(escolha > 33){
                    gotoxy(escolha,14);
                    printf(" ");
                    escolha -= 25;
                    gotoxy(escolha,14);
                    printf("%c", 175);
                }
                break;
            case RIGHT :
                if(escolha < 58){
                    gotoxy(escolha,14);
                    printf(" ");
                    escolha += 25;
                    gotoxy(escolha,14);
                    printf("%c", 175);
                }
                break;
            case ENTER :
                if(escolha == 33)
                    strcpy(cons.frmpg, cc.pln);
                else
                    strcpy(cons.frmpg, "Dinheiro");
                break;

            setbuf(stdin,NULL);
        }
	} while (e != ENTER);

	// aleatoriza o ID
	struct consultas verifica;
	voltaID:
	do{
        srand(time(NULL));
        cons.ID = rand()%999999;
        if(cons.ID <= 100000){
            cons.ID += 100000;
        }
	} while (cons.ID <= 100000);
	arq = fopen(arqConsultas, "rb");
	while(!feof(arq)){
        fread(&verifica, sizeof(struct consultas), 1, arq);
        if(verifica.ID == cons.ID){
            fclose(arq);
            goto voltaID;
        }
	}
	fclose(arq);
    // copia o email para a consulta e passa 0 para o status
    strcpy(cons.email, cc.email);
    cons.status = 0;
    // passa tudo pra arquivo
    arq = fopen(arqConsultas, "ab");
    fwrite(&cons, sizeof(struct consultas), 1, arq);
    fclose(arq);

	system("cls");

	bordaext(BLUE);
	bordacliente(BLUE);

	CriarCaixinha(43,12,13,14,24,"  CONSULTA REGISTRADA!  ");

    setbuf(stdin,NULL);

	return;
}

void listarmedicos(){
	int i, Yaux = 11;
	bordaext(BLUE);
    bordacliente(BLUE);
    bordaperfil();
	titulo("MEDICOS DISPONIVEIS",BLUE);

	gotoxy(25,10);
	printf("%c",204);
	for (i = 0; i < 60; i++)
		printf("%c",205);
	printf("%c",185);
	gotoxy(57,8); printf("%c",203);
	gotoxy(57,9); printf("%c",186);
	gotoxy(57,10); printf("%c",202);

	gotoxy(28,9);
	printf("M%cDICO",144);
	gotoxy(60,9);
	printf("ESPECIALIDADE");
	FILE *arq = fopen(arqMedico, "rb");
	while(!feof(arq)){
        if(fread(&cm, sizeof(struct cadastroMedico), 1, arq) == 1){
            gotoxy(28,Yaux);
            printf("%s", cm.nome);
            gotoxy(60,Yaux);
            printf("%s", cm.espc);
            Yaux++;
        }
	}

    getch();

	system("cls");
	fclose(arq);

	return;
}

void excluirconsulta(){
	int i;
	FILE *arq1, *arq2;
	int ID;
	char txt[] = "                                                     ";
	char e;

	bordaext(BLUE);
	bordaesp();
	titulo("EXCLUIR CONSULTA",BLUE);
	gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c    EXCLUIR CONSULTA    %c",185,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",188);

    CriarCaixinha(28,10,11,12,53,txt);
    gotoxy(30,11);
    printf("ID DE CONSULTA:");
    textcolor(LIGHTGRAY);
    gotoxy(29,14);
    printf("Todas as consultas possuem um ID de identifica%c%co.",135,198);
    gotoxy(29,15);
    printf("Quando confirmar, n%co ser%c possivel desfazer.",198,160);

	textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    setbuf(stdin, NULL);
    textcolor(WHITE);
	gotoxy(46,11);
    scanf("%d", &ID);

    arq1 = fopen(arqConsultas, "rb");
    arq2 = fopen(auxConsultas, "ab");

    while(fread(&cons, sizeof(struct consultas), 1, arq1) == 1){
        if(ID != cons.ID){
            fwrite(&cons, sizeof(struct consultas), 1, arq2);
        }
    }

    fclose(arq1);
    fclose(arq2);
    remove(arqConsultas);
    rename(auxConsultas, arqConsultas);

    system("cls");

    return;
}

void consultasclient(){
    FILE *arq;
    int col = 10;
	int i;
	char e, nome[30], medico[20];

    setbuf(stdin, NULL);

    textcolor(RED);
    gotoxy(13, 21);
    printf("X - Cancelado");
    textcolor(GREEN);
    gotoxy(13,22);
    printf("V - Confirmado");
    textcolor(LIGHTGRAY);
    gotoxy(13,23);
    printf("... - Aguardando");

    bordaext(BLUE);
    bordacliente(BLUE);
    titulo("CONSULTAS",BLUE);

    listarcaixax(12,7);
    //preenchimento dos textos
    gotoxy(14,8);
    printf("CONSULTA");
    gotoxy(40,8);
    printf("DATA/HOR%cRIO",181);
    gotoxy(62,8);
    printf("M%cDICO",144);
    gotoxy(80,8);
    printf("ID DE CONSULTA");

    arq = fopen(arqConsultas, "rb");

    while(fread(&cons, sizeof(struct consultas), 1, arq) == 1){
        if (!strcmp(cc.email,cons.email)){
            gotoxy(14,col);
            strcpy(nome,cons.nome);
            strupr(nome);
            printf("%s", nome);
            if (strlen(nome) >= 14){
                gotoxy(20,col);
                printf("...");
            }
            gotoxy(38,col);
			printf("%s",cons.data);
			gotoxy(50,col);
			printf("%s",cons.hora);
			gotoxy(58,col);
            strcpy(medico, cons.medico);
            strupr(medico);
            printf("%s", medico);
			gotoxy(84,col);
			printf("%d",cons.ID);
			if(cons.status == 0){
                    textcolor(LIGHTGRAY);
                    gotoxy(32 ,col);
                    printf("...");
                    textcolor(BLUE);
                } else {
                    if(cons.status == 1){
                        textcolor(GREEN);
                        gotoxy(32 ,col);
                        printf("V");
                        textcolor(BLUE);
                    } else {
                        if(cons.status == 2){
                            textcolor(RED);
                            gotoxy(32 ,col);
                            printf("X");
                            textcolor(BLUE);
                        }
                    }
                }
			col++;
        }
    }

    fclose(arq);

	textcolor(GREEN);
	CriarCaixinha(79,21,22,23,19,"   NOVA CONSULTA   ");
	textcolor(RED);
	CriarCaixinha(53,21,22,23,20,"  EXCLUIR CONSULTA  ");

	gotoxy(77,22);
	textcolor(GREEN);
	printf("%c",175);
	int aux = 77;
	while (e != ENTER){
		gotoxy(aux,22);
		e = getch();
		switch(e){
			case LEFT:
				gotoxy(77,22);
				printf(" ");
				aux-=27;
				if (aux == 50){
					gotoxy(aux,22);
					textcolor(RED);
					printf("%c",175);
				}else{
					aux+=27;
				}
				break;
			case RIGHT:
				gotoxy(50,22);
				printf(" ");
				aux+=27;
				if (aux == 77){
					gotoxy(aux,22);
					textcolor(GREEN);
					printf("%c",175);
				}else{
					aux-=27;
				}
				break;
			case ENTER:
				if (aux == 77){
					system("cls");
					novaconsulta();
				}else{
					if (aux == 50){
						system("cls");
						excluirconsulta();
					}
				}break;
			case ESC:
			    return;
				break;
			}
	}

    return;
}

void nullCons(){
        struct consultas auxiliar;
    int i;
	FILE *arq1 = NULL, *arq2 = NULL;
	int ID;
	char txt[] = "                                                     ";
	char e;

	bordaext(BLUE);
	bordaesp();
	titulo("CANCELAR CONSULTA",BLUE);
	gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c   CANCELAR CONSULTA    %c",185,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",188);

    CriarCaixinha(28,10,11,12,53,txt);
    gotoxy(30,11);
    printf("ID DE CONSULTA:");
    textcolor(LIGHTGRAY);
    gotoxy(29,14);
    printf("Todas as consultas possuem um ID de identifica%c%co.",135,198);
    gotoxy(29,15);
    printf("Quando confirmar, n%co ser%c possivel desfazer.",198,160);

	textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    setbuf(stdin, NULL);
    textcolor(WHITE);
	gotoxy(46,11);
    scanf("%d", &ID);

    arq1 = fopen(arqConsultas, "rb");
    arq2 = fopen(auxConsultas, "wb");

    while(fread(&cons, sizeof(struct consultas), 1, arq1) == 1){
        if(ID != cons.ID){
            fwrite(&cons, sizeof(struct consultas), 1, arq2);
        } else {
            auxiliar = cons;
        }
    }
    auxiliar.status = 2;
    fwrite(&auxiliar, sizeof(struct consultas), 1, arq2);

    fclose(arq1);
    fclose(arq2);
    remove(arqConsultas);
    rename(auxConsultas, arqConsultas);

    system("cls");

    return;
}

void confCons(){
    struct consultas auxiliar;
    int i;
	FILE *arq1 = NULL, *arq2 = NULL;
	int ID;
	char txt[] = "                                                     ";
	char e;

	bordaext(BLUE);
	bordaesp();
	titulo("CONFIRMAR CONSULTA",BLUE);
	gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c   CONFIRMAR CONSULTA   %c",185,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",188);

    CriarCaixinha(28,10,11,12,53,txt);
    gotoxy(30,11);
    printf("ID DE CONSULTA:");
    textcolor(LIGHTGRAY);
    gotoxy(29,14);
    printf("Todas as consultas possuem um ID de identifica%c%co.",135,198);
    gotoxy(29,15);
    printf("Quando confirmar, n%co ser%c possivel desfazer.",198,160);

	textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    setbuf(stdin, NULL);
    textcolor(WHITE);
	gotoxy(46,11);
    scanf("%d", &ID);

    arq1 = fopen(arqConsultas, "rb");
    arq2 = fopen(auxConsultas, "wb");

    while(fread(&cons, sizeof(struct consultas), 1, arq1) == 1){
        if(ID != cons.ID){
            fwrite(&cons, sizeof(struct consultas), 1, arq2);
        } else {
            auxiliar = cons;
        }
    }
    auxiliar.status = 1;
    fwrite(&auxiliar, sizeof(struct consultas), 1, arq2);

    fclose(arq1);
    fclose(arq2);
    remove(arqConsultas);
    rename(auxConsultas, arqConsultas);

    system("cls");

    return;

}

void consultasmed(){
    int col = 10;
	int i, aux = 75;
	char e;

	textcolor(RED);
    gotoxy(13, 21);
    printf("X - Cancelado");
    textcolor(GREEN);
    gotoxy(13,22);
    printf("V - Confirmado");
    textcolor(LIGHTGRAY);
    gotoxy(13,23);
    printf("... - Aguardando");

    bordaext(BLUE);
    bordacliente(BLUE);
    titulo("CONSULTAS",BLUE);

    listarcaixax(12,7);
    //preenchimento dos textos
    gotoxy(14,8);
    printf("ID DE CONSULTA");
    gotoxy(30,8);
    printf("STATUS");
    gotoxy(40,8);
    printf("DATA/HOR%cRIO",181);
    gotoxy(61,8);
    printf("PACIENTE");
    gotoxy(78,8);
    printf("FORMA DE PAGAMENTO");

        // busca todas as referencias ao nome do medico
        FILE *arq = fopen(arqConsultas, "rb");
        while(fread(&cons, sizeof(struct consultas), 1, arq) == 1){
            if(!strcmp(cm.nome, cons.medico)){
                gotoxy(14, col);
                printf("%i", cons.ID);
                gotoxy(38, col);
                printf("%s", cons.data);
                gotoxy(50, col);
                printf("%s", cons.hora);
                // encontra o nome do arquivo de cadastros
                FILE *aux = fopen(arqCliente, "rb");
                while(fread(&cc, sizeof(struct cadastroCliente), 1, aux) == 1){
                    if(!strcmp(cc.email,cons.email)){
                        gotoxy(58, col);
                        printf("%s", cc.nome);
                    }
                }
                fclose(aux);
                gotoxy(84, col);
                printf("%s", cons.frmpg);
                if(cons.status == 0){
                    textcolor(LIGHTGRAY);
                    gotoxy(32 ,col);
                    printf("...");
                    textcolor(BLUE);
                } else {
                    if(cons.status == 1){
                        textcolor(GREEN);
                        gotoxy(32 ,col);
                        printf("V");
                        textcolor(BLUE);
                    } else {
                        if(cons.status == 2){
                            textcolor(RED);
                            gotoxy(32 ,col);
                            printf("X");
                            textcolor(BLUE);
                        }
                    }
                }

                col++;
            }
        }
        fclose(arq);

        textcolor(GREEN);
        CriarCaixinha(73, 21, 22, 23, 24, "   CONFIRMAR CONSULTA   ");
        textcolor(RED);
        CriarCaixinha(46, 21, 22, 23, 24, "   CANCELAR CONSULTA    ");
        textcolor(LIGHTGRAY);
        CriarCaixinha(31, 21, 22, 23, 12, "   VOLTAR   ");

        textcolor(WHITE);
        gotoxy(aux, 22);
        printf("%c", 175);

        while (e != ENTER){
		e = getch();
		switch(e){
			case LEFT:
			    if(aux == 75){
                    gotoxy(aux, 22);
                    printf(" ");
                    aux-= 27;
                    gotoxy(aux, 22);
                    printf("%c", 175);
			    } else {
                    if(aux == 48){
                        gotoxy(aux, 22);
                        printf(" ");
                        aux-= 15;
                        gotoxy(aux, 22);
                        printf("%c", 175);
                    }
			    }
				break;
			case RIGHT:
				if(aux == 48){
                    gotoxy(aux, 22);
                    printf(" ");
                    aux+= 27;
                    gotoxy(aux, 22);
                    printf("%c", 175);
				} else {
                    if(aux == 33){
                        gotoxy(aux, 22);
                        printf(" ");
                        aux+= 15;
                        gotoxy(aux, 22);
                        printf("%c", 175);
                    }
				}
				break;
			case ENTER:
				switch (aux){
                    case 75 :
                        system("cls");
                        confCons();
                        break;
                    case 48 :
                        system("cls");
                        nullCons();
                        break;
                    case 33 :
						system("cls");
						return;
						break;
                }
				break;
			case ESC:
			    system("cls");
			    return;
				break;
        }
	}
}

void alterarCliente(){
    FILE *arq1, *arq2;
    struct cadastroCliente auxiliar;
    system("cls");
    char espaco[] = "                                ";
    int aux = 10, seleciona;

    // passando as informações para uma variável reserva
    auxiliar = cc;

    // Explicação de como funciona para o usuário
    textcolor(LIGHTGRAY);
    gotoxy(40,24);
    printf("SETAS -> Movimentam o cursor");
    gotoxy(40, 25);
	printf("ENTER -> Escolhe o que alterar");

	bordaext(BLUE);
    bordaperfil();
    titulo("ALTERAR",BLUE);

	gotoxy(32,10);
	printf("NOME: %s", cc.nome);
	gotoxy(32,11);
	printf("SOBRENOME: %s", cc.sobrenome);
	gotoxy(32,12);
	printf("PLANO DE SA%cDE: %s", 233, cc.pln);
	gotoxy(32,13);
	printf("DATA DE NASCIMENTO: %s", cc.nascimento);
	gotoxy(32,14);
	printf("SEXO: %s", cc.sx);
	gotoxy(32,15);
	printf("VOLTAR");

    textcolor(WHITE);
	gotoxy(30, aux);
	printf("%c", 175);

	while(seleciona != ENTER){
        char tecla = getch();
        switch (tecla){
            case DOWN :
                if(aux < 15){
                    gotoxy(30, aux);
                    printf(" ");
                    aux++;
                    gotoxy(30, aux);
                    printf("%c", 175);
                }
                break;
            case UP :
                if(aux > 10){
                    gotoxy(30, aux);
                    printf(" ");
                    aux--;
                    gotoxy(30, aux);
                    printf("%c", 175);
                }
                break;
            case ENTER : {
                textcolor(YELLOW);
                switch (aux){    // melhor usar switch/case do que ifs aninhados
                    case 10 :
                        gotoxy(38 ,aux);
                        puts(espaco);
                        gotoxy(38 ,aux);
                        gets(auxiliar.nome);
                        textcolor(WHITE);
                        gotoxy(31, aux);
                        break;
                    case 11 :
                        gotoxy(43 ,aux);
                        puts(espaco);
                        gotoxy(43 ,aux);
                        gets(auxiliar.sobrenome);
                        textcolor(WHITE);
                        gotoxy(31, aux);
                        break;
                    case 12 :
                        gotoxy(48 ,aux);
                        puts(espaco);
                        if(!strcmp(auxiliar.pln, "PLN 1")){
                            gotoxy(48, aux);
                            printf("PLN 2");
                            strcpy(auxiliar.pln, "PLN 2");
                        } else {
                            if(!strcmp(auxiliar.pln, "PLN 2")){
                                gotoxy(48, aux);
                                printf("-");
                                strcpy(auxiliar.pln, "-");
                            } else {
                                if(!strcmp(auxiliar.pln, "-")){
                                    gotoxy(48, aux);
                                    printf("PLN 1");
                                    strcpy(auxiliar.pln, "PLN 1");
                                }
                            }
                        }
                        textcolor(WHITE);
                        gotoxy(31, aux);
                        break;
                    case 13 :
                        gotoxy(52 ,aux);
                        puts(espaco);
                        gotoxy(52 ,aux);
                        gets(auxiliar.nascimento);
                        textcolor(WHITE);
                        gotoxy(31, aux);
                        break;
                    case 14 :
                        gotoxy(38 ,aux);
                        puts(espaco);
                        gotoxy(38 ,aux);
                        gets(auxiliar.sx);
                        textcolor(WHITE);
                        gotoxy(31, aux);
                        break;
                    case 15 :
                        // aplicando alterações
                        arq1 = fopen(arqCliente, "rb");
                        arq2 = fopen(ARQ_AUX, "ab");
                        while(fread(&cc, sizeof(struct cadastroCliente), 1, arq1) == 1){
                            if(strcmp(cc.email, auxiliar.email)){
                                fwrite(&cc, sizeof(struct cadastroCliente), 1, arq2);
                            }
                        }
                        // finalizando processos
                        cc = auxiliar;
                        fwrite(&cc, sizeof(struct cadastroCliente), 1, arq2);
                        fclose(arq1);
                        fclose(arq2);

                        remove(arqCliente);
                        rename(ARQ_AUX, arqCliente);

                        // limpar sa bagaça e voltar
                        system("cls");
                        return;
                        break;
                }
            }
        }
	}

	getchar();
	system("cls");
}

int cursorperfilcliente(){
    int aux = 44, seleciona;
    textcolor(BLUE);
    bordaext(BLUE);

    CriarCaixinha(42, 18, 19, 20, 12, "   VOLTAR   ");
    CriarCaixinha(58, 18, 19, 20, 13, "   ALTERAR   ");
    gotoxy(aux, 19);
    printf("%c", 175);

    while(seleciona != ENTER){
        char tecla = getch();
        switch(tecla){
            case RIGHT :
                if(aux < 60){
                    gotoxy(aux, 19);
                    printf(" ");
                    aux += 16;
                    gotoxy(aux, 19);
                    printf("%c", 175);
                }
                break;
            case LEFT :
                if(aux > 44){
                    gotoxy(aux, 19);
                    printf(" ");
                    aux -= 16;
                    gotoxy(aux, 19);
                    printf("%c", 175);
                }
                break;
            case ENTER :
                if(aux == 44)
                    return 1;
                else
                    alterarCliente();
                    return 0;
                break;
        }
    }

}

void perfilcliente(){
	int i;
	volta:
	bordaext(BLUE);
    bordaperfil();
    titulo("MINHA CONTA",BLUE);

	gotoxy(29,10);
	printf("Nome: %s", cc.nome);
	gotoxy(29,11);
	printf("Sobrenome: %s", cc.sobrenome);
	gotoxy(29,12);
	printf("Email: %s", cc.email);
	gotoxy(29,13);
	printf("Plano de Sa%cde: %s", 163, cc.pln);
	gotoxy(29,14);
	printf("CPF: %s", cc.cpf);
	gotoxy(29,15);
	printf("Data de Nascimento: %s", cc.nascimento);
	gotoxy(29,16);
	printf("Sexo: %s", cc.sx);

	i = cursorperfilcliente();
	if(!i)
        goto volta;

	system("cls");
}

void alterarMedico(){
    FILE *arq1, *arq2;
    struct cadastroMedico auxiliar;
    system("cls");
    char espaco[] = "                                ";
    int aux = 10, seleciona;
    // passando as informações para uma variável reserva
    auxiliar = cm;

    // Explicação de como funciona para o usuário
    textcolor(LIGHTGRAY);
    gotoxy(40,24);
    printf("SETAS -> Movimentam o cursor");
    gotoxy(40, 25);
	printf("ENTER -> Escolhe o que alterar");

	bordaext(BLUE);
    bordaperfil();
    titulo("ALTERAR",BLUE);

	gotoxy(32,10);
	printf("NOME: %s", cm.nome);
	gotoxy(32,11);
	printf("SOBRENOME: %s", cm.sobrenome);
	gotoxy(32,12);
	printf("DATA DE NASCIMENTO: %s", cm.nascimento);
	gotoxy(32,13);
	printf("SEXO: %s", cm.sx);
	gotoxy(32,14);
	printf("VOLTAR");

    textcolor(WHITE);
	gotoxy(30, aux);
	printf("%c", 175);

	while(seleciona != ENTER){
        char tecla = getch();
        switch (tecla){
            case DOWN :
                if(aux < 14){
                    gotoxy(30, aux);
                    printf(" ");
                    aux++;
                    gotoxy(30, aux);
                    printf("%c", 175);
                }
                break;
            case UP :
                if(aux > 10){
                    gotoxy(30, aux);
                    printf(" ");
                    aux--;
                    gotoxy(30, aux);
                    printf("%c", 175);
                }
                break;
            case ENTER : {
                textcolor(YELLOW);
                switch (aux){    // melhor usar switch/case do que ifs aninhados
                    case 10 :
                        gotoxy(38 ,aux);
                        puts(espaco);
                        gotoxy(38 ,aux);
                        gets(auxiliar.nome);
                        textcolor(WHITE);
                        gotoxy(30, aux);
                        break;
                    case 11 :
                        gotoxy(43 ,aux);
                        puts(espaco);
                        gotoxy(43 ,aux);
                        gets(auxiliar.sobrenome);
                        textcolor(WHITE);
                        gotoxy(30, aux);
                        break;
                    case 12 :
                        gotoxy(52 ,aux);
                        puts(espaco);
                        gotoxy(52 ,aux);
                        gets(auxiliar.nascimento);
                        textcolor(WHITE);
                        gotoxy(30, aux);
                        break;
                    case 13 :
                        gotoxy(38 ,aux);
                        puts(espaco);
                        gotoxy(38 ,aux);
                        gets(auxiliar.sx);
                        textcolor(WHITE);
                        gotoxy(30, aux);
                        break;
                    case 14 :
                        // aplicando alterações
                        arq1 = fopen(arqMedico, "rb");
                        arq2 = fopen(ARQ_AUX, "ab");
                        while(fread(&cm, sizeof(struct cadastroMedico), 1, arq1) == 1){
                            if(strcmp(cm.crm, auxiliar.crm)){

                            }
                        }
                        // Finalizando operações
                        cm = auxiliar;
                        fwrite(&cm, sizeof(struct cadastroMedico), 1, arq2);
                        fclose(arq1);
                        fclose(arq2);
                        remove(arqMedico);
                        rename(ARQ_AUX, arqMedico);

                        // limpar sa bagaça e voltar
                        system("cls");
                        return;
                        break;
                }
            }
        }
	}

	getchar();
	system("cls");
}

int cursorperfilmed(){
    int aux = 44, seleciona;
    textcolor(BLUE);
    bordaext(BLUE);

    CriarCaixinha(42, 18, 19, 20, 12, "   VOLTAR   ");
    CriarCaixinha(58, 18, 19, 20, 13, "   ALTERAR   ");
    gotoxy(aux, 19);
    printf("%c", 175);

    while(seleciona != ENTER){
        char tecla = getch();
        switch(tecla){
            case RIGHT :
                if(aux < 60){
                    gotoxy(aux, 19);
                    printf(" ");
                    aux += 16;
                    gotoxy(aux, 19);
                    printf("%c", 175);
                }
                break;
            case LEFT :
                if(aux > 44){
                    gotoxy(aux, 19);
                    printf(" ");
                    aux -= 16;
                    gotoxy(aux, 19);
                    printf("%c", 175);
                }
                break;
            case ENTER :
                if(aux == 44)
                    return 1;
                else
                    alterarMedico();
                    return 0;
                break;
        }
    }

}

void perfilmed(){
	int i;
	volta:
	bordaext(BLUE);
    bordaperfil();
    titulo("MINHA CONTA",BLUE);

	gotoxy(29,10);
	printf("Nome: %s", cm.nome);
	gotoxy(29,11);
	printf("Sobrenome: %s", cm.sobrenome);
	gotoxy(29,12);
	printf("Especialidade: %s", cm.espc);
	gotoxy(29,13);
	printf("Email: %s", cm.email);
	gotoxy(29,14);
	printf("CRM: %s", cm.crm);
	gotoxy(29,15);
	printf("CPF: %s", cm.cpf);
	gotoxy(29,16);
	printf("Data de Nascimento: %s", cm.nascimento);
	gotoxy(29,17);
	printf("Sexo: %s", cm.sx);

	i = cursorperfilmed();
	if(!i)
        goto volta;

	system("cls");
}

int segclient(){
    int i, v;
    char confrm[15];

	//tela de informação
	bordaext(BLUE);
    bordaesp();
    gotoxy(30,10);
    printf("A Equipe Medizin se  importa com a sua seguran%ca.", 135);
    gotoxy(30,11);
    printf("Para evitar futuros transtornos, preencha os cam-");
    gotoxy(30,12);
    printf("pos a seguir.");

    wait();
    gotoxy(40,15);
    printf("Pressione ENTER para continuar");
	getch();
	system("cls");

	//tela dados de segurança
    bordaext(BLUE);
    bordaesp();
    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c    DADOS DE SEGURAN%cA   %c",185,128,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",188);

    gotoxy(28,10);
    printf("Senha:");
    gotoxy(28,12);
    printf("Confirmar senha:");

    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

	textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ESC %c Voltar     ENTER %c Confirmar",175,175);
    textcolor(RED);
    gotoxy(18,26);
    printf("Para voltar para janela anterior, preencha os campos com 0 e pressione ESC");

    voltsenha:
	textcolor(WHITE);
	gotoxy(35,10);
	printf("                              ");
    lersenha(35,10,cc.senha);
    setbuf(stdin,NULL);

    lersenha(45, 12, confrm);
    setbuf(stdin,NULL);

    if(strcmp(cc.senha, confrm)){
        textcolor(RED);
        gotoxy(45, 12);
        printf("As senhas nao coincidem!          ");
        Sleep(1000);
        gotoxy(45, 12);
        printf("                                  ");
        goto voltsenha;
    }

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    getch();
    system("cls");

    // Opção de escolher um plano de saúde
    plnds();

    // Passando tudo pra aquivo
    FILE *arq = fopen(arqCliente, "ab");
    fwrite(&cc, sizeof(struct cadastroCliente), 1, arq);
    fclose(arq);

	bordaext(BLUE);
	int t = 0;
	do{
		i = 8;
		while(i < 16){
			textcolor(i);
    		CriarCaixinha(37,12,13,14,35,"  CADASTRO REALIZADO COM SUCESSO!  ");
    		Sleep(50);
    		i++;
			}
		t++;
	}while(t <= 3);

	system("cls");
}


int cadclient(){
    int i, v;
    bordaext(BLUE);
    bordaesp();

    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c     DADOS PESSOAIS      %c",185,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }

    printf("%c",188);
    textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ENTER %c Confirmar",175,175);
    gotoxy(27, 20);
    printf("Para voltar, preencha os campos com 0");

    /* Imprime na tela o que deverá ser preenchido */
	textcolor(BLUE);
    gotoxy(28,10);
    printf("Nome:");
    gotoxy(28,11);
    printf("Sobrenome:");
    gotoxy(28,12);
    printf("E-mail:");
    gotoxy(28,13);
    printf("CPF:");
    gotoxy(28,14);
    printf("Nascimento:");
    gotoxy(28,15);
    printf("Sexo:");

    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    /* Obtém as informações */
    textcolor(WHITE);
    nome:
    gotoxy(34,10);
    v = verificastr(cc.nome,34,10);
    if (v == -1){
    	goto nome;
	}
    setbuf(stdin,NULL);

    sobrenome:
    gotoxy(39,11);
    v = verificastr(cc.sobrenome,39,11);
    if (v == -1){
    	goto sobrenome;
	}
    setbuf(stdin,NULL);

    e_mail:
    gotoxy(36,12);
    v = verificastr(cc.email,36,12);
    if (v == -1){
    	goto e_mail;
	}
    setbuf(stdin,NULL);
    strlwr(cc.email);
    setbuf(stdin,NULL);

    // verificação de e-mail
    struct cadastroCliente verConta;
    FILE *arq = fopen(arqCliente, "rb");

    while(!feof(arq)){
        fread(&verConta, sizeof(struct cadastroCliente), 1, arq);
        if(!strcmp(verConta.email, cc.email)){
            fclose(arq);
            textcolor(RED);
            gotoxy(36, 12);
            printf("Este e-mail j%c foi cadastrado!", 160);
            Sleep(1000);
            gotoxy(36, 12);
            printf("                                   ");
            textcolor(WHITE);
            goto e_mail;
        }
    }

    fclose(arq);

    gotoxy(33,13);
    lercpf_Cliente();
    gotoxy(54,13);
    printf("           ");

    gotoxy(40,14);
    textcolor(LIGHTGRAY);
    printf("Utilize no formato DD/MM/AAAA");
    getch();
    gotoxy(40,14);
    printf("                             ");
    textcolor(WHITE);
    gotoxy(40,14);
    gets(cc.nascimento);
    setbuf(stdin,NULL);

    sexo:
    gotoxy(34,15);
    v = verificastr(cc.sx,34,15);
    if (v == -1){
    	goto sexo;
	}

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    getch();
    if(!strcmp(cc.cpf, "0") || !strcmp(cc.email, "0")){
        return 0;
    }

    system("cls");
    segclient();

}

int loginmed(int *op){
    FILE *arq;
    char crm[14], senha[15];
    int i, v, l;
    char txt[47] = "                                              ";
    bordaext(BLUE);
    bordaesp();

    CriarCaixinha(32,10,11,12,46,txt); /* INTERFACE AREA DE LOGIN*/
    CriarCaixinha(32,13,14,15,46,txt);
    gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 21; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c    %cREA DE LOGIN    %c",185,181,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 21; i++){
        printf("%c",205);
    }
    printf("%c",188);
    textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ESC %c Voltar     ENTER %c Confirmar",175,175);
    textcolor(RED);
    gotoxy(18,26);
    printf("Para voltar para janela anterior, preencha os campos com 0 e pressione ESC");

	textcolor(BLUE);
    gotoxy(34,11);
    printf("CRM:");
    gotoxy(34,14);

    printf("SENHA:");
    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"      ENTRAR      ");

    textcolor(WHITE);
    acre:
    gotoxy(39,11);
    gets(crm);
    setbuf(stdin,NULL);
    strupr(crm);
    setbuf(stdin,NULL);
    // verificação de crm
    arq = fopen(arqMedico, "rb");
    while(!feof(arq)){
        fread(&cm, sizeof(struct cadastroMedico), 1, arq);
        if(!strcmp(crm, "0") || !strcmp(crm, cm.crm)){
            fclose(arq);
            break;
        }

        if(feof(arq)){
            textcolor(RED);
            gotoxy(39,11);
            printf("CRM N%co registrado!          ", 198);
            fclose(arq);
            Sleep(1000);
            gotoxy(39,11);
            printf("                              ");
            textcolor(WHITE);
            goto acre;
        } else {
            textcolor(GREEN);
        }
    }

    fclose(arq);

    // verificação de senha
    voltsenha:
    textcolor(WHITE);
    setbuf(stdin,NULL);
    l = lersenha(41,14,senha);
    setbuf(stdin,NULL);

    if(!strcmp(senha,"0") || !strcmp(senha, cm.senha)){}
    else {
        textcolor(RED);
        gotoxy(41,14);
        printf("Senha Incorreta!               ");
        Sleep(1000);
        gotoxy(41,14);
        printf("                               ");
        goto voltsenha;
    }

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"      ENTRAR      ");
    gotoxy(65,19);
    printf("%c",175);


    // volta para a tela anterior
    *op = getch();

    if(!strcmp(crm,"0") || !strcmp(senha,"0"))
        *op = ESC;

    if(*op == ESC){
        return ESC;
    }else{
        menu(op);
        return ESC;
    }
}

int logincliente(int *op){ //login
    FILE *arq;
    char email[30], senha[15], l;
    int i, v;
    char txt[47] = "                                              ";
    bordaext(BLUE);
    bordaesp();
    strcpy(cm.crm, "0"); // Diferencia o cliente do médico

    CriarCaixinha(32,10,11,12,46,txt); /* INTERFACE AREA DE LOGIN*/
    CriarCaixinha(32,13,14,15,46,txt);
    gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 21; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c    %cREA DE LOGIN    %c",185,181,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 21; i++){
        printf("%c",205);
    }
    printf("%c",188);
    textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ESC %c Voltar     ENTER %c Confirmar",175,175);
    textcolor(RED);
    gotoxy(18,26);
    printf("Para voltar para janela anterior, preencha os campos com 0 e pressione ESC");

	textcolor(BLUE);
    gotoxy(34,11); /* LEITURA DOS CAMPOS */
    printf("EMAIL:");
    gotoxy(34,14);
    printf("SENHA:");
    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"      ENTRAR      ");

    e_mail:
    textcolor(WHITE);
    gotoxy(41,11);
    gets(email);
    setbuf(stdin,NULL);
    strlwr(email);
    setbuf(stdin,NULL);
    // verificação de email
    arq = fopen(arqCliente, "rb");
    while(fread(&cc, sizeof(struct cadastroCliente), 1, arq) == 1){
        if(!strcmp(cc.email, email) && !strcmp(email, "0")){
            fclose(arq);
            break;
        }

        if(feof(arq)){
            textcolor(RED);
            gotoxy(41,11);
            printf("Email n%co registrado!          ", 198);
            fclose(arq);
            Sleep(1000);
            gotoxy(41,11);
            printf("                              ");
            textcolor(WHITE);
            goto e_mail;
        }
    }

    // verificação de senha
    voltsenha:
    textcolor(WHITE);
    setbuf(stdin,NULL);
    l = lersenha(42,14,senha);
    setbuf(stdin,NULL);
    if(!strcmp(senha, "0") || !strcmp(senha, cc.senha)){}
    else {
        textcolor(RED);
        gotoxy(41,14);
        printf("Senha Incorreta!               ");
        Sleep(1000);
        gotoxy(41,14);
        printf("                               ");
        goto voltsenha;
    }
    setbuf(stdin,NULL);

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"      ENTRAR      ");
    gotoxy(65,19);
    printf("%c",175);

    fclose(arq);

    // volta para a tela anterior
    *op = getch();

    if(!strcmp(email,"0") || !strcmp(senha,"0"))
        *op = ESC;

    if(*op == ESC){
        return ESC;
    }else{
        menu(op);
        return ESC;
    }
}

void especialidade(){
	int i;
	char txt[47] = "                                              ";
	bordaext(BLUE);
    bordaesp();

    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c      %cREA DA SA%cDE      %c",185,181,233,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",188);

    CriarCaixinha(32,11,12,13,46,txt);
    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    gotoxy(34,12);
    printf("ESPECIALIDADE:");

    char e;
    textcolor(WHITE);
    gotoxy(49,12);
    gets(cm.espc);

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    getch();
    system("cls");


    /* Passa todas as informações para o arquivo */
    FILE *arq = fopen(arqMedico, "ab");
    fwrite(&cm, sizeof(struct cadastroMedico), 1, arq);

    fclose(arq);
    /* Mensagem de Sucesso de Cadastro */
    bordaext(BLUE);
	int t = 0;
	do{
		i = 8;
		while(i < 16){
			textcolor(i);
    		CriarCaixinha(37,12,13,14,35,"  CADASTRO REALIZADO COM SUCESSO!  ");
    		Sleep(50);
    		i++;
			}
		t++;
	}while(t <= 3);
	getch();
	system("cls");
}

void segmed(){
    struct cadastroMedico verConta;
	int i, v;
	char confrm[15];

	//tela de informação
	bordaext(BLUE);
    bordaesp();
    gotoxy(30,10);
    printf("A Equipe Medizin agradece-lhes pela prefer%cncia!",136);
    gotoxy(30,11);
    printf("Preencha os campos a seguir para sua seguran%ca e", 135);
    gotoxy(30,12);
    printf("seu conforto");

    wait();
    gotoxy(40,15);
    printf("Pressione ENTER para continuar");
	getch();
	system("cls");

	//tela dados de segurança
    bordaext(BLUE);
    bordaesp();
    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c    DADOS DE SEGURAN%cA   %c",185,128,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",188);

    gotoxy(28,10);
    printf("CRM:");
    gotoxy(28,12);
    printf("Senha:");
    gotoxy(28, 14);
    printf("Confirmar senha:");


    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

	textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ESC %c Voltar     ENTER %c Confirmar",175,175);
    textcolor(RED);
    gotoxy(18,26);
    printf("Para voltar para janela anterior, preencha os campos com 0 e pressione ESC");

    crm:
	textcolor(WHITE);
    gotoxy(33,10);
    v = verificastr(cm.crm,33,10);
    if (v == -1){
    	goto crm;
	}
    setbuf(stdin,NULL);
    strupr(cm.crm);
    setbuf(stdin,NULL);

    // verificar se o crm já existe
    FILE *arq = fopen(arqMedico, "rb");
    while(!feof(arq)){
        fread(&verConta, sizeof(struct cadastroMedico), 1, arq);
        if(!strcmp(cm.crm, verConta.crm)){
            fclose(arq);
            textcolor(RED);
            gotoxy(33,10);
            printf("CRM j%c registrado!", 160);
            Sleep(1000);
            gotoxy(33,10);
            printf("                    ");
            goto crm;
        }
    }

    fclose(arq);

    voltsenha:
    textcolor(WHITE);
    gotoxy(35,12);
    printf("                                  ");
    gotoxy(35,12);
    lersenha(35, 12, cm.senha);
    setbuf(stdin,NULL);

    gotoxy(45,14);
    lersenha(45, 14, confrm);
    setbuf(stdin,NULL);

    if(strcmp(cm.senha, confrm)){
        textcolor(RED);
        gotoxy(45, 14);
        printf("As senhas n%co coincidem!          ", 198);
        Sleep(1000);
        gotoxy(45, 14);
        printf("                                  ");
        goto voltsenha;
    }

    textcolor(GREEN);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    getch();
    system("cls");

	especialidade();
}

int cadmed(){
	int i, v;
    bordaext(BLUE);
    bordaesp();

    gotoxy(43,6);
    printf("%c",201);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(43,7);
    printf("%c     DADOS PESSOAIS      %c",185,204);
    gotoxy(43,8);
    printf("%c",200);
    for (i = 0; i < 25; i++){
        printf("%c",205);
    }
    printf("%c",188);
    textcolor(LIGHTGRAY);
    gotoxy(27,19);
    printf("ENTER %c Confirmar",175,175);

    /* Imprime na tela os campos para preencher */
	textcolor(BLUE);
    gotoxy(28,10);
    printf("Nome:");
    gotoxy(28,11);
    printf("Sobrenome:");
    gotoxy(28,12);
    printf("E-mail:");
    gotoxy(28,13);
    printf("CPF:");
    gotoxy(28,14);
    printf("Nascimento:");
    gotoxy(28,15);
    printf("Sexo:");

    textcolor(LIGHTGRAY);
    gotoxy(27, 20);
    printf("Para voltar, preencha os campos com 0");

    textcolor(BLUE);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");

    /* Obtém as informações */
    textcolor(WHITE);
    nome:
    gotoxy(34,10);
    v = verificastr(cm.nome,34,10);
    if (v == -1){
    	goto nome;
	}
    setbuf(stdin,NULL);

    sobrenome:
    gotoxy(39,11);
    v = verificastr(cm.sobrenome,39,11);
    if (v == -1){
    	goto sobrenome;
	}
    setbuf(stdin,NULL);

    e_mail:
    gotoxy(36,12);
    v = verificastr(cm.email,36,12);
    if (v == -1){
    	goto e_mail;
	}
	setbuf(stdin,NULL);
	strlwr(cm.email);
	setbuf(stdin,NULL);

	// verificar o e-mail
	FILE *arq = fopen(arqMedico, "rb");
	struct cadastroMedico verConta;

    while(!feof(arq)){
        fread(&verConta, sizeof(struct cadastroMedico), 1, arq);
        if(!strcmp(verConta.email, cm.email)){
            fclose(arq);
            textcolor(RED);
            gotoxy(36, 12);
            printf("Este e-mail j%c foi cadastrado!", 160);
            Sleep(1000);
            gotoxy(36, 12);
            printf("                                   ");
            textcolor(WHITE);
            goto e_mail;
        }
    }

    fclose(arq);

    gotoxy(33,13);
    setbuf(stdin,NULL);
    lercpf_Medico();
    setbuf(stdin,NULL);
    gotoxy(54,13);
    printf("           ");
    gotoxy(40,14);
    textcolor(LIGHTGRAY);
    printf("Utilize no formato DD/MM/AAAA");
    getch();
    gotoxy(40,14);
    printf("                             ");
    textcolor(WHITE);
    gotoxy(40,14);
    gets(cm.nascimento);
    setbuf(stdin,NULL);
    sexo:
    gotoxy(34,15);
    v = verificastr(cm.sx,34,15);
    if (v == -1){
    	goto sexo;
	}
    setbuf(stdin,NULL);

    textcolor(YELLOW);
    CriarCaixinha(67,18,19,20,18,"     CONTINUAR    ");
    getch();
    system("cls");
    if(!strcmp(cm.cpf, "0") || !strcmp(cm.email, "0")){
        return 0;
    }
    segmed();
}

void opcadastro(){
	int i;
	bordaext(BLUE);
	bordaesp();

	gotoxy(33,18);
	textcolor(LIGHTGRAY);
	printf("Escolha uma das op%c%ces acima para registrar-se",135,228);
	gotoxy(50,20);
	printf("ESC %c Voltar", 175);

	textcolor(BLUE);
	gotoxy(45,6);
    printf("%c",201);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",187);
    gotoxy(45,7);
    printf("%c    OP%C%CO DE CADASTRO   %c",185,128,199,204);
    gotoxy(45,8);
    printf("%c",200);
    for (i = 0; i < 24; i++){
        printf("%c",205);
    }
    printf("%c",188);

	CriarCaixinha(45,10,11,12,26,"          CLIENTE         ");
    CriarCaixinha(45,13,14,15,26,"          MEDICO          ");

    int s;
	s = cursorcad(43,11);
		switch (s){
			case 1:
				system("cls");
				cadclient();
				break;
			case 2:
				system("cls");
				cadmed();
				break;
            case 0:
                return;
                break;
		}
}

void admlog(){
	system("cls");
	system("color 0f");
	textcolor(DARKGRAY);
	bordaext(DARKGRAY);
	titulo("ACESSO ADMINISTRADOR",DARKGRAY);
	gotoxy(6,3);
	textbackground(BLACK);
	bordacliente(DARKGRAY);
	logo(DARKGRAY,15,11);
	bordalogo(DARKGRAY,12,9);

	int i;
	textcolor(LIGHTGRAY);
	gotoxy(7,26);
	printf("Administrador");

    //escreve por cima da função bordacliente pra ficar escrito com cinza claro
    char dateStr[9];
	char timeStr[6];
    gotoxy(84,26);
    printf("%s",__DATE__);
    printf(" / ");
    gotoxy(98,26);
    _strtime(timeStr);
    for (i = 0; i < 5; i++){
    	printf("%c",timeStr[i]);
	}

	gotoxy(62,7);
	printf("MOVE [DOWN/UP]");
	gotoxy(62,8);
	printf("SELECT [ENTER]");
	cursoradm();

	system("cls");
}

void opcaodelogin(int *op){
    int d;
    volta:
    system("color 0F");
    bordaext(BLUE);
    textcolor(WHITE);

    gotoxy(10,9);
    printf("A Medizin trabalha diariamente para levar mais");
    gotoxy(10,10);
    printf("sa%cde e qualidade de vida para seus clientes.",163);
    gotoxy(10,13);
    printf("Selecione um meio de login");
    gotoxy(10,14);
    printf("Se esta %c sua primeira vez, selecione registrar-se",130);

    textcolor(BLUE);
    CriarCaixinha(70,9,10,11,26,"          CLIENTE         ");
    CriarCaixinha(70,12,13,14,26,"          MEDICO          ");
    CriarCaixinha(70,15,16,17,26,"       REGISTRAR-SE       ");
    textcolor(WHITE);
    d = cursoresp(67,10);
        system("cls");
        if (d == 1){
            logincliente(op);
            system("cls");
            goto volta;
        }else{
            if (d == 2){
                loginmed(op);
                system("cls");
                goto volta;

            }else{
            	if(d == 3){
            		opcadastro();
                    system("cls");
                    goto volta;
				} else {
                    if (d == 0){
                        system("cls");
                        goto volta;
                    }
				}
            }
        }
}

int menu(int *op){
	int i, cursor;

	Sleep(100);
    carregando();
    menu:
    system("cls");

	bordaext(BLUE);
	bordacliente(BLUE);
	logo(BLUE,17,11);
	bordalogo(BLUE,14,9);


	gotoxy(45,4);
	if(!strcmp(cm.crm , "0")){
        printf("Bem-vindo(a), %s!",cc.nome);
	} else {
        printf("Bem-vindo(a), %s!",cm.nome);
	}

	gotoxy(25,5);
	printf("A Medizin conta com voc%c para melhorar sempre a qualidade",136);
	gotoxy(35,6);
	printf("do atendimento e dos servi%cos prestados.",135);
	CriarCaixinha(45,10,11,12,18,"   MEDICAMENTOS   ");
	CriarCaixinha(70,10,11,12,18,"     CONSULTAS    ");
	CriarCaixinha(45,13,14,15,18,"   MINHA CONTA    ");
	CriarCaixinha(70,13,14,15,18,"       SAIR       ");


	textcolor(LIGHTGRAY);
	gotoxy(49,22);
    printf("Setas Direcionais %c Seleciona a Op%c%co",175,135,198);
    gotoxy(52,23);
    printf("ESC %c Sair    ENTER %c Confirmar",175,175);


    textcolor(GREEN);
    cursor = cursormenu(42,11);
    	switch(cursor){
    		case 0:
    			system("cls");
    			return 0; //vai pra coisa de login
    			break;
    		case 1:
    			system("cls");
    			int m;
				m = medicamentos();
				if (m == 0){
					goto menu;
				}
    			break;
    		case 2:
    		    system("cls");
    		    if(!strcmp(cm.crm , "0")){
                    perfilcliente();
    		    } else {
                    perfilmed();
    		    }
    		    goto menu;
    			break;
    		case 3:
    			system("cls");
    			if (!strcmp(cm.crm , "0")){
    				consultasclient();
				}else{
					consultasmed();
				}
				goto menu;
    			break;
    		case 4:
    			system("cls");
    			return 0;
    			break;
		}
}

/* ***********ARQUIVOS********** */

void criaArquivos(void){
    FILE *arq;

    // cria aquivo do cliente e verifica se há erros
    arq = fopen(arqCliente, "ab");
    if(arq == NULL){
        textcolor(RED);
        printf("BANCO DE DADOS DE CLIENTES N%cO PODE SER CRIADO!", 199);
        exit(1);
    }
    fclose(arq);

    // cria arquivo do médico e verifica se há erros
    arq = fopen(arqMedico, "ab");
    if(arq == NULL){
        textcolor(RED);
        printf("BANCO DE DADOS DE MEDICOS N%cO PODE SER CRIADO!", 199);
        exit(1);
    }
    fclose(arq);

    // cria aquivo de consultas e verifica se há erros
    arq = fopen(arqConsultas, "ab");
    if(arq == NULL){
        textcolor(RED);
        printf("BANCO DE DADOS DE CONSULTAS N%cO PODE SER CRIADO!", 199);
        exit(1);
    }
    fclose(arq);

    // cria arquivo de medicamentos e verifica se há erros
    arq = fopen(arqMedicamentos, "ab");
    if(arq == NULL){
        textcolor(RED);
        printf("BANCO DE DADOS DE CONSULTAS N%cO PODE SER CRIADO!", 199);
        exit(1);
    }
    fclose(arq);

    arq = fopen("medicamentos.txt", "ab");
    if(arq == NULL){
        textcolor(RED);
        printf("BANCO DE DADOS DE MEDICAMENTOS N%cO PODE SER CRIADO!", 199);
        exit(1);
    }
    fclose(arq);

    return;
}

                    /* ************** FUNÇÃO PRINCIPAL ************** */

int main(){
    /* Definições de Layout Iniciais*/
	SetConsoleTitle("Assistencia Medica Medizin");
	system("mode con:cols=115 lines=30"); //ajusta o tamanho da tela
    system("color 0f");

    int op, i; /* Declaração de variáveis iniciais do programa */

    criaArquivos();/* Pré-Processamento de Arquivos*/

    /* Programa */
    volta:
    carregando();
	opcaodelogin(&op);
    goto volta;
	getch();
	end();
    return 0;
}
