#include "./Word.h"

void Word :: input_word(){
  cout << "Введите текст : " << endl;
  string tmp;
  cin >> tmp;
  strcpy(word, tmp);
}

void Word :: output_word(){
  cout << word;
}

void Word :: input_word_from_file(string filename) {
  fstream fin(filename);
  string tmp;
  fin >> tmp;
  strcpy(word, tmp);
}

void Word :: output_word_to_file(string filename) {
  ofstream fout(filename);
  fout << word;
}

void Word :: split_word(){
  char sub[SUBL];
  memset(sub,'\0',SUBL);//заполняем буфер нулями
  strcpy(buf,word);//копируем слово в буфер
  int pos = 0, len = strlen(word), i = 1;
  while(i < len){
    if(i+2 < len){
      //проверка первого условия из задания
      //
      if(IsConsonant(word[i-1]) && IsVowel(word[i]) &&
                                                  IsVowel(word[i+1]) ){
        InsertDash(buf,i+1+pos);
        pos++;
      } else
      //проверка второго условия из задания
      //
      if(IsVowel(word[i-1]) && IsConsonant(word[i]) && IsConsonant(word[i+1]) &&
                                      ContainVowel(Substr(word,sub,i+2,0))){
        InsertDash(buf,i+1+pos);
        pos++;
      } else
      //проверка третьего условия из задания
      //
      if(IsLetter(word[i-1]) && IsVowel(word[i]) &&
         ContainVowel(SubString(word,sub,i+1,2))){
        InsertDash(buf,i+1+pos);
        pos++;
      }
      //обработка случая, когда два первых символа гласные
      if(i == 1 && IsVowel(word[i-1])  &&
         ContainVowel(SubString(word,sub,i,2))){
        InsertDash(buf,i);
        pos++;
      }
    }
    i++;
  }
  cout << buf;
}

void Word :: input_by_parts() {
	cout << "Скільки префіксів? (0-3): ";
	cin >> countPref;
	if (countPref == 1) {
		cout << "Префікс: ";
		cin >> pref;
		
	}
	else if (countPref == 2) {
		string pref1;
		cout << "Префікс (1): ";
		cin >> pref;
		cout << "Префікс (2): ";
		cin >> pref1;
		
		pref += pref1;
	}
	else if (countPref == 3) {
		string pref1, pref2;
		cout << "Префікс (1): ";
		cin >> pref;
		
		cout << "Префікс (2): ";
		cin >> pref1;
		
		cout << "Префікс (3): ";
		cin >> pref2;

		pref += pref1 + pref2;
	}
  cout << "Скільки коренів? (1-2): ";
	cin >> countCorin;
  if (countCorin == 1) {
		cout << "Корінь: ";
	  cin >> corin;
	}
	else if (countCorin == 2) {
		string cor1;
		cout << "Корінь (1): ";
		cin >> pref;
		cout << "Корінь (2): ";
		cin >> cor1;
		pref += cor1;
	}
	cout << "Скільки суфіксів? (0-3): ";
	cin >> countSuf;
	if (countSuf == 1) {
		cout << "Суфікс: ";
		cin >> suf;
		
	}
	else if (countSuf == 2) {
		string suf1;
		cout << "Суфікс (1): ";
		cin >> suf;
		cout << "Суфікс (2): ";
		cin >> suf1;
		suf += suf1;
	}
	else if (countSuf == 3) {
		string suf1, suf2;
		cout << "Суфікс (1): ";
		cin >> pref;
		cout << "Суфікс (2): ";
		cin >> suf1;
		cout << "Суфікс (3): ";
		cin >> suf2;

		suf += suf1 + suf2;
	}
	cout << "Закінчення: ";
	cin >> ending;
}
void Word :: output_by_parts(){
  cout << pref << corin << suf << ending << endl;
}
