#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>


char ch[34]="АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", cH[34]="АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ", chastot[34]="ОЕАИТНСРВЛ", CH[34]="абвгдеёжзийклмнопрстуфхцчшщъыьэюя", zamen[34], words[409600][100], tekst[409600], backCh1[1000], backCh2[1000];
int stat[33], all = 0, word[409600], wkol = 0, teks=0, bch=0, dot=1;

void sortnah() {
	int t, l;
	char q;
	for(int i = 0; i<33; i++) {
		t = stat[i];
		q = ch[i];
		l = i - 1;
		while(l >= 0 && stat[l]<t) {
			stat[l + 1] = stat[l];
			ch[l + 1] = ch[l];
			l--;
		}
		stat[l + 1] = t;
		ch[l + 1] = q;
	}
}

int anuka(int p) {
	int pp = 0;
		for (int uu = 0; uu < p; uu++) {
			pp = 0;
			while(words[p][pp]){
				if (words[uu][pp] != words[p][pp]) { goto wer; }
				pp++;
			}
			if(words[uu][pp] == words[p][pp]) return 0;
		wer:;
	}
		return 1;
}

//00000000000000000000000000000000000000000000000000000000000000000000000000000
void input(){
for (int i = 0; i < 33; i++) stat[i] = 0;
char filename[100];
printf("Input file name:");
scanf("%s", &filename);
FILE *f = fopen(filename, "r");
char c = 'h';
while (!feof(f)) {
repeat:
	char C = c;
	c = fgetc(f);
	if (feof(f)) { break; }
	if ((c == '.') || (c == ';') || (c == '*') || (c == '!') || (c == '?') || ((C == ':') && (c == '\n'))) { dot = 100; }
	else
		if (c == ' ') { dot++; }
		else dot = 0;
	tekst[teks++]=c;
	for (int i = 0; i < 33; i++) { if (c == ch[i]) { 
		if (dot == 1) { for (int i = 0; i < 33; i++) if (cH[i] == c) { dot = 0; words[wkol][strlen(words[wkol])] = CH[i]; tekst[teks-1] = CH[i];  goto suda; } } else { suda: words[wkol][strlen(words[wkol])] = c; }
		words[wkol][strlen(words[wkol])] = '\0';  stat[i]++; all++; goto repeat; } }
	word[wkol] = strlen(words[wkol]);
	wkol++;
}
tekst[teks]='\0';
fclose(f);
}
//00000000000000000000000000000000000000000000000000000000000000000000000000000

//=============================================================================
void outStat() {
	printf("\n");
	for (int i = 0; i < 33; i++) { printf("%c - %3.3f", ch[i], double(stat[i]) / double(all)); if (chastot[i]) printf(" -> %c", chastot[i]); printf("\n"); }
}
//=============================================================================


//-----------------------------------------------------------------------------
void outAllWord() {
	int r = 1;
	while (r < 100) {
		printf("\n------------------------------------------------------------------------\n");
	again:
		if (r == 100) break;
		int t = 0;
		for (int e = 0; e < wkol - 1; e++) { if (word[e] == r) { if (anuka(e)) { printf("%s ", words[e]); t = 1; } } }
		if (t == 0) { r++; goto again; }
		r++;
	}
}
//-----------------------------------------------------------------------------

//99999999999999999999999999999999999999999999999999999999999999999999999999999
void outText(){
	teks=0;
	while(tekst[teks]) printf("%c",tekst[teks++]);
	printf("\n");
}
//99999999999999999999999999999999999999999999999999999999999999999999999999999


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Zamen(){
	printf("\n");
	for (int i = 0; i < 26; i++) printf("%2d ", i);
	printf("\n");
	for (int i = 0; i < 26; i++) printf(" %c ", cH[i]);
	printf("\n");
	for (int i = 0; i < 26; i++) printf(" %c ", CH[i]);
	printf("\n\n");
	for (int i = 26; i < 33; i++) printf("%3d", i);
	printf("\n");
	for (int i = 26; i < 33; i++) printf(" %c ", cH[i]);
	printf("\n");
	for (int i = 26; i < 33; i++) printf(" %c ", CH[i]);
	printf("\n");
	printf("\nInput two symbols:"); char g = 'n', h = 'n'; int A = 0; scanf("%d", &A); g = cH[A]; scanf("%d", &A); h = CH[A];  printf("  %c^%c\n", g, h);
	backCh1[bch++]=g;
	backCh2[bch-1]=h;
	teks=0;
	while(tekst[teks]) if(tekst[teks++]==g) tekst[teks-1]=h;

	for (int i = 0; i < 33; i++) if (cH[i] == g) { for (int iii = 0; iii < 33; iii++) if(CH[iii]==h) zamen[i] = cH[iii]; }

	int kk=0,ll=0;
	for(kk=0; kk<wkol; kk++) { 
		for(ll=0; ll<word[kk]; ll++) { if(words[kk][ll]==g) words[kk][ll]=h; }
	}
	printf("Changing completed.\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Zamena(char g, char h){
	teks=0;
	while(tekst[teks]) if(tekst[teks++]==g) tekst[teks-1]=h;

	for (int i = 0; i < 33; i++) if(cH[i]==h) zamen[i] = ' ';

	int kk=0,ll=0;
	for(kk=0; kk<wkol; kk++) { 
		for(ll=0; ll<word[kk]; ll++) { if(words[kk][ll]==g) words[kk][ll]=h; }
	}
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//*****************************************************************************
void outKey() {
	for (int i = 0; i < 33; i++) printf("%c|", cH[i]);
	printf("\n");
	for (int i = 0; i < 33; i++) printf("%c|", zamen[i]);
	printf("\n");
}
//*****************************************************************************


//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void saveText() {
	FILE *ff = fopen("output.txt", "w");
	int kolvo = 0;
	while (tekst[kolvo]) { fputc(tekst[kolvo++], ff); }
	fputc('\n', ff);
	for (int i = 0; i < 33; i++) { fputc(cH[i],ff); fputc('|', ff); }
	fputc('\n', ff);
	for (int i = 0; i < 33; i++) { fputc(zamen[i], ff); fputc('|', ff); }
	fputc('\n', ff);
	fclose(ff);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
void backChChar() {
	char cha = 'n'; 
	printf("\n");
	for (int i = 0; i < 26; i++) printf("%2d ", i);
	printf("\n");
	for (int i = 0; i < 26; i++) printf(" %c ", cH[i]);
	printf("\n");
	for (int i = 26; i < 33; i++) printf("%3d", i);
	printf("\n");
	for (int i = 26; i < 33; i++) printf(" %c ", cH[i]);
	printf("\n");
	printf("Введите символ, который нужно вернуть:");
    int AA = 0; scanf("%d", &AA); cha = cH[AA];
	for (int i = 0; i < 33; i++) if(backCh1[i]==cha) Zamena(backCh2[i], backCh1[i]);
}
//zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz


int main()
{	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	input();
	//system("chcp 1251");
	sortnah();
	int kom = 0;
	while (1) {
		printf("Input command (begining - 0, outAllWord - 1, outStat - 2, outText - 3, ChangeChar - 4, backChar - 5, Отмена замены символа - 6, outKey - 7, saveText - 8):");
		scanf("%d", &kom);
		if (kom == 0) input();
		if (kom == 1) outAllWord();
		if (kom == 2) outStat();		
		if (kom == 3) outText();
		if (kom == 4) Zamen();
		if (kom == 5) Zamena(backCh2[--bch],backCh1[bch]);
		if (kom == 6) backChChar();
		if (kom == 7) outKey();
		if (kom == 8) saveText();
		printf("\n");
	}
	
    return 0;
}

