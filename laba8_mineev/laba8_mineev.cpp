#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>


char ch[34] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß", cH[34] = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß", autoList[34] = "îåàèíòñğâëêìäïóÿûüãçá÷éõæøşöùıôú¸", chastot[34] = "ÎÅÀÈÒÍÑĞÂËÊÌÄÏÓßÛÜÃÇÁ×ÉÕÆØŞÖÙİÔÚ¨", CH[34] = "àáâãäå¸æçèéêëìíîïğñòóôõö÷øùúûüışÿ", zamen[34], words[409600][100], tekst[409600], backCh1[1000], backCh2[1000];
int stat[33], steps[1000], step=0, all = 0, word[409600], unChipWord[409600], wkol = 0, teks = 0, bch = 0, dot = 1;

void sortnah() {
	int t, l;
	char q;
	for (int i = 0; i<33; i++) {
		t = stat[i];
		q = ch[i];
		l = i - 1;
		while (l >= 0 && stat[l]<t) {
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
		while (words[p][pp]) {
			if (words[uu][pp] != words[p][pp]) { goto wer; }
			pp++;
		}
		if (words[uu][pp] == words[p][pp]) return 0;
	wer:;
	}
	return 1;
}

//00000000000000000000000000000000000000000000000000000000000000000000000000000
void input() {
	wkol = 0; teks = 0; bch = 0; dot = 10000; step = 0;
	all = 0;
	ch[34] = char("ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß");
	for (int i = 0; i < 33; i++) stat[i] = 0;
	char filename[100];
	printf("Input file name:");
	scanf("%s", &filename);
	FILE *f = fopen(filename, "r");
	char c = 'h'; int ki = 0;
	while (!feof(f)) {
	repeat:
		char C = c;
		c = fgetc(f);
		if (feof(f)) { break; }
		if ((c == '.') || (c == ';') || (c == '*') || (c == '!') || (c == '?') || ((C == ':') && (c == '\n'))) { dot = 999; }
		else { dot++; }
			tekst[teks++] = c;
			for (int i = 0; i < 33; i++) {
				if (c == ch[i]) {
					if (dot > 1000) { for (int i = 0; i < 33; i++) if (cH[i] == c) { dot = 0; words[wkol][strlen(words[wkol])] = CH[i]; tekst[teks - 1] = CH[i]; ki = 1; } }
					else {  words[wkol][strlen(words[wkol])] = c; }
					words[wkol][strlen(words[wkol])] = '\0';  stat[i]++; all++; goto repeat;
				}
			}
			word[wkol] = strlen(words[wkol]);
			unChipWord[wkol] = word[wkol] - ki; ki = 0;
			wkol++;
	}
	tekst[teks] = '\0';
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


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void outByUnChip() {
	int r = 1;
	while (r < 100) {
		printf("\n------------------------------------------------------------------------\n");
	again1:
		if (r == 100) break;
		int t = 0;
		for (int e = 0; e < wkol - 1; e++) { if (unChipWord[e] == r) { if (anuka(e)) { printf("%s ", words[e]); t = 1; } } }
		if (t == 0) { r++; goto again1; }
		r++;
	}
}
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//99999999999999999999999999999999999999999999999999999999999999999999999999999
void outText() {
	teks = 0;
	printf("\n");
	while (tekst[teks]) printf("%c", tekst[teks++]);
	printf("\n");
}
//99999999999999999999999999999999999999999999999999999999999999999999999999999


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Zamen(int mod, char g, char h) {
	if (mod == 0) {
		printf("\n");
		printf("\nInput two symbols:"); g = 'n'; h = 'n';scanf(" %c%c", &g, &h);  printf("  %c^%c\n", g, h);
	}
	backCh1[bch++] = g;
	backCh2[bch - 1] = h;
	teks = 0;
	while (tekst[teks]) if (tekst[teks++] == g) tekst[teks - 1] = h;

	for (int i = 0; i < 33; i++) if (cH[i] == g) { for (int iii = 0; iii < 33; iii++) if (CH[iii] == h) { zamen[i] = cH[iii]; steps[step++] = i; } }

	int kk = 0, ll = 0;
	for (kk = 0; kk<wkol; kk++) {
		for (ll = 0; ll < word[kk]; ll++) { if (words[kk][ll] == g) { words[kk][ll] = h; for (int i = 0; i < 33; i++){ if (cH[i] == h) unChipWord[kk]++; if (CH[i] == h) unChipWord[kk]--; } }
	}
	}
	printf("Changing completed.\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Zamena(char g, char h) {
	teks = 0;
	while (tekst[teks]) if (tekst[teks++] == g) tekst[teks - 1] = h;

	for (int i = 0; i < 33; i++) if (cH[i] == h) zamen[i] = ' ';

	int kk = 0, ll = 0;
	for (kk = 0; kk<wkol; kk++) {
		for (ll = 0; ll < word[kk]; ll++) { if (words[kk][ll] == g) { words[kk][ll] = h; unChipWord[kk]++; } }
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
	for (int i = 0; i < 33; i++) { fputc(cH[i], ff); fputs(" - ", ff); fputc(zamen[i], ff); fputc('\n', ff); }
	fputs("\n--------------------------------------------------------------\n", ff);
	for (int i = 0; i < 33; i++) { fputc(cH[steps[i]], ff); fputs("->", ff); fputc(zamen[steps[i]], ff); fputc('\n', ff); }
	fclose(ff);
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
void backChChar() {
	char cha = 'n';
	printf("\n");
	printf("Ââåäèòå ñèìâîë, êîòîğûé íóæíî âåğíóòü:");
	scanf(" %c", &cha);
	for (int i = 0; i < 33; i++) if (backCh1[i] == cha) Zamena(backCh2[i], backCh1[i]);
}
//zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void autoChipher() {
	for (int zx = 0;zx < 33;zx++) Zamen(1, ch[zx], autoList[zx]);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


int main()
{
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// øğèôò
	CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof font;
	font.nFont = 1;
	font.dwFontSize = { 9, 18 };
	font.FontFamily = 0 | FF_DONTCARE & ~TMPF_FIXED_PITCH;
	font.FontWeight = FW_NORMAL;
	wcscpy_s(font.FaceName, LF_FACESIZE, L"Lucida Console");
	input();
	//system("chcp 1251");
	sortnah();
	int kom = 0;
	while (1) {
		printf("Input command (begining - -1, outAllWord - 0, outByUnChip - 1, outStat - 2, outText - 3, ChangeChar - 4, backChar - 5, Îòìåíà çàìåíû ñèìâîëà - 6, outKey - 7, saveText - 8, autoChipher - 9):");
		scanf("%d", &kom);
		if (kom == -1) input();
		if (kom == 0) outAllWord();
		if (kom == 1) outByUnChip();
		if (kom == 2) outStat();
		if (kom == 3) outText();
		if (kom == 4) Zamen(0,'n','n');
		if (kom == 5) Zamena(backCh2[--bch], backCh1[bch]);
		if (kom == 6) backChChar();
		if (kom == 7) outKey();
		if (kom == 8) saveText();
		if (kom == 9) autoChipher();
		printf("\n");
	}

	return 0;
}