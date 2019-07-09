// https://www.urionlinejudge.com.br/judge/pt/problems/view/1840
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);
#define endl '\n'

using namespace std;

int rodadas;
char manilha, lixo;
string s1 = "4567QJKA23", s2 = "DSHC", carta;
map <char, int> figura, naipe;

void init();

struct tipo
{
	string nome;
	int id;
	int chute;
	int carta_figura, carta_naipe;
	int pontos=0;
	int resultado;
} pessoa[4];

bool cmp(tipo a, tipo b)
{
	if (a.carta_figura > b.carta_figura) return true;
	if (a.carta_figura == b.carta_figura && a.carta_naipe > b.carta_naipe) return true;
	return false;
}

bool arruma(tipo a, tipo b)
{
	if (a.id < b.id) return true;
	return false;
}

bool escolhe_vencedor(tipo a, tipo b)
{
	if (a.resultado < b.resultado) return true;
	return false;
}

int main()
{_
	cin >> rodadas >> manilha >> lixo;
	for (int i=0; i<(int)s1.size(); i++) if (s1[i]==manilha)
	{
		manilha = s1[(i+1)%10];
		s1.erase((i+1)%10, 1);
		break;
	}
	s1 = s1 + manilha;

	init();
	
	for (int i=0; i<4; pessoa[i].id=i, i++)
		cin >> pessoa[i].nome >> pessoa[i].chute;
		
	for (int i=0; i<rodadas; i++)
	{
	
		for (int j=0; j<4; j++)
		{
			cin >> carta;
			pessoa[j].carta_figura = figura[carta[0]];
			pessoa[j].carta_naipe = naipe[carta[1]];
		}
		
		sort(pessoa, pessoa + 4, cmp);
		
		pessoa[0].pontos++;
		pessoa[0].pontos-=(pessoa[0].carta_figura == pessoa[1].carta_figura && pessoa[0].carta_figura != figura[manilha]);
		
		sort(pessoa, pessoa + 4, arruma);
	}
	
	for (int i=0; i<4; i++) pessoa[i].resultado = abs(pessoa[i].chute - pessoa[i].pontos);
	
	sort(pessoa, pessoa + 4, escolhe_vencedor);
	
	if (pessoa[0].resultado == pessoa[1].resultado) cout << '*';
	else cout << pessoa[0].nome;
	cout << endl;

	return 0;
}

void init()
{
	for (int i=0; i<(int)s1.size(); i++)
		figura[s1[i]] = i;
	for (int i=0; i<(int)s2.size(); i++)
		naipe[s2[i]] = i;
}

