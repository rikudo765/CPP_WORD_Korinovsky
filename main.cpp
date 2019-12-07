#include "./src/Word.h";

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Rus");
    Word word;
    word.input_word();
    word.split_word();
    word.input_by_parts();
    word.output_by_parts();
}
