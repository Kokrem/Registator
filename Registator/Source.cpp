#include <iostream>
int cont = 0;

using namespace std;

struct registos
{
	float valor;
	char tipo;
	short int dia;
	short int mes;
	short int ano;
};
struct registos registadeira[1000];
void menu();
void op1();
void op2();
void op3();
void op4();
void op5();
void op6();
void op7();
void op8();
void op9();

void main(void)
{
	int op;

	do
	{
		system("cls");
		menu();
		scanf_s("%d", &op);
		switch (op)
		{
		case 1: op1(); break; // Inserir ( gastos ou receitas)
		case 2: op2(); break; // Listar ( gastos ou receitas)
		case 3: op3(); break; // Editar ( gastos ou receitas)
		case 4: op4(); break; // Média
		case 5: op5(); break; // Saldo
		case 6: op6(); break; // Listar a partir da data
		case 7: op7(); break; // Listar a partir de certo valor ( gastos ou receitas)
		default:
			break;
		}
	} while (op != 0);

}

void op1() // Inserir
{
	system("cls");
	printf("Que tipo de registo quer inserir ( R para receita G para gasto): ");
	cin >> registadeira[cont].tipo;
	if (registadeira[cont].tipo == 'g' || registadeira[cont].tipo == 'G')
	{
		printf("\nInsira o valor do seu gasto: ");
		scanf_s("%f", &registadeira[cont].valor);
	}
	else if (registadeira[cont].tipo == 'R' || registadeira[cont].tipo == 'r')
	{
		printf("\nInsira o valor da sua receita: ");
		scanf_s("%f", &registadeira[cont].valor);
	}
	cout << "Insira a data (exemplo 19 03 1995): ";
	scanf_s("%hd %hd %hd", &registadeira[cont].dia, &registadeira[cont].mes, &registadeira[cont].ano);
	cont++;
}
void op2() // Listar
{
	int i;
	char a;
	system("cls");
	cout << "Insira que tipo quer listar (R para receita G para gasto): ";
	cin >> a;
	for (i = 0; i <= cont; i++)
	{
		if (a == registadeira[i].tipo && a == 'g')
		{
			printf("\n%.2f\t Gasto \t %hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
		}
		else if (a == registadeira[i].tipo && a == 'r')
		{
			printf("\n%.2f\t Receita \t %hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
		}
	}
	system("pause");
}
void op3() // Editar
{
	system("cls");
	int reg;
	cout << "Que registo quer editar? (até agora foram inseridos " << cont << " ): ";
	cin >> reg;
	cout << "Quer alterar o tipo do registo para receita(r) ou para gasto(g):";
	cin >> registadeira[reg].tipo;
	cout << "Altere o valor do registo";
	cin >> registadeira[reg].valor;
	cout <<endl<< "Altere a data do registo ( exemplo 19 03 1995):";
	cin >> registadeira[reg].dia >> registadeira[reg].mes >> registadeira[reg].ano;
}
void op4() // Media
{
	system("cls");
	int i , somaf=-1;
	float media, soma =0;
	char a;
	cout << "Quer ver a media de gastos(g) ou receitas(r)?";
	cin >> a;
	for (i = 0; i <= cont; i++)
	{
		if (registadeira[i].tipo = 'a')
		{
			soma += registadeira[i].valor;
			somaf+=1;
		}
		
	}
	media = float(soma / somaf);
	if (a == 'r')
	{
		printf("A media de receitas e: %.2f\n",media);
	}
	else if (a == 'g')
	{
		printf("A media de gastos e: %.2f\n", media);
	}
	system("pause");
}
void op5() // Saldo
{
	system("cls");
	float somar = 0, somag = 0,saldo;
	int i;
	for (i = 0; i <= cont; i++)
	{
		if (registadeira[i].tipo == 'r')
		{
			somar += registadeira[i].valor;
		}
		if (registadeira[i].tipo == 'g')
		{
			somag += registadeira[i].valor;
		}
	}
	saldo = somar - somag;
	cout << "Saldo = " << saldo<< endl;
	system("pause");
}
void op6() // Listar a partir da data
{
	system("cls");
	short int i, ano, mes, dia;
	char tipo;
	cout << "Quer procurar receitas(r) ou gastos(g)";
	cin >> tipo;
	cout << endl<< "Procurar registos a partir de:";
	cin>>dia>>mes>>ano;
	system("cls");
	for (i = 0; i < cont; i++)
	{
		if (registadeira[i].ano >= ano)
		{
			if (registadeira[i].mes >= mes)
			{
				if (registadeira[i].dia >= dia)
				{
					if (registadeira[i].tipo == tipo && registadeira[i].tipo == 'r')
					{
						printf("%.2lf%\tReceita\t%hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
					}
					else if (registadeira[i].tipo == tipo && registadeira[i].tipo == 'g')
					{
						printf("%.2lf%\tGasto\t%hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
					}
				}
			}
		}
	}
	system("pause");
}

void op7()
{
	system("cls");
	int i;
	float valor;
	char tipo;
	cout << "Quer procurar receitas(r) ou gastos(g)";
	cin >> tipo;
	if (tipo == 'r')
	{
		cout << endl << "Procurar receitas a partir do valor:";
	}
	else if (tipo == 'g')
	{
		cout << endl << "Procurar gastos a partir do valor:";
	}
	cin >> valor;
	for (i = 0; i <= cont; i++)
	{
		if (tipo == registadeira[i].tipo && registadeira[i].tipo == 'r')
		{
			printf("%.2lf%\tReceita\t%hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
		}
		else if (registadeira[i].tipo == tipo && registadeira[i].tipo == 'g')
		{
			printf("%.2lf%\tGasto\t%hd/%hd/%hd\n", registadeira[i].valor, registadeira[i].dia, registadeira[i].mes, registadeira[i].ano);
		}
		
	}
}
void menu()
{
	printf("1 - Inserir registos de receita ou gasto\n");
	printf("2 - Listar registos de gastos ou receitas\n");
	printf("3 - Editar registos\n");
	printf("4 - Media de receita ou gastos\n");
	printf("5 - Apresentar saldo\n");
	printf("6 - Apresentar gastos apartir certa data\n");
	printf("7 - Apresentar gastos acima de...\n\n");
	printf("Insira uma opcao:");
}