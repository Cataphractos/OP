#include <stdio.h>
#include <stdlib.h> //добавил, чтобы пользоваться rand`ом
#define X 20
#define Y 20

struct cell{
    unsigned live:1;
}; // создал структуру, чтобы уменьшить нагрузку и время выполнения
// т.к. нам нужны только значения 0 и 1 имеет смысл использовать один бит для переменной, в которой храним
// состояние каждой клетки

void fillHeaderVal( int val,int placeHigh, unsigned char* header) {

    header[placeHigh] = ((val & 0xFF000000) >> (6*4));
    header[placeHigh - 1] = ((val & 0x00FF0000) >> (4*4));
    header[placeHigh - 2] = ((val & 0x0000FF00) >> (2*4));
    header[placeHigh - 3] = (val & 0x000000FF);

}

void rd(int r, struct cell field[X][Y], int x, int y){

    int a;
    int counter;
    counter=0;

    while (counter != X*Y) {
        a=rand()%100;
        if (a>r){
            field[x][y].live=0;
            x++;
            if (x==10){
                x=0;
                y++;

            }
        }
        else if (a <= r){
            field[x][y].live=1;
            x++;
            if (x==10){
                x=0;
                y++;

            }}
        counter++;
    };
}


int main() {
    struct cell field[X][Y];
    struct cell actual[X][Y];
    int x, y, nb;
    int r;
    y = 0;
    x = 0;
    nb = 0;
    int e;


    char c;
    char array[54+(X*Y*9)];
    FILE *ff;
    ff = fopen("source.bmp", "r");
//заголовок бмп-файла занимает 54, чтобы определить цвет клетки необходимо 9 символов (или 3) (например 255, 255, 255)
//получается, что массив, в который мы переписываем значение бмп-файла равен
for (long int i=0; i < 54+(X*Y*9) ; i++){
        c=getc(ff);
        array[i]=c;
}
        fclose(ff);


long int i = 54;


while (y < 10) {

        if (array[i] == 2) { //
            field[x][y].live = 1;
            x++;
            i = i + 9; // прибавляю 9, т.к. дальше идёт 55255255
            if (x == X) {
                x = 0;
                y++;
            }
        } else if (array[i] == 0) {
            field[x][y].live = 0;
            x++;
            i = i + 3; // прибавляю 3, т.к. дальше идёт 00
            if (x == X) {
                x = 0;
                y++;
            }

    }
}


    y = 0;
    x = 0;
    int d = 0;
    while (d != X) {
        //обхожу массив, смотрю соседей каждой клетки и в зависимости от их состояние добавляю +1 к переменной ng
        while (y != X) {
            x = 0;
            while (x != X) { //каждая клетка имеет восемь соседей, осуществляю 8 сравнений
                if (field[x][y + 1].live == 1) {
                    nb++;
                }
                if (field[x + 1][y + 1].live == 1) {
                    nb++;
                }
                if (field[x + 1][y].live == 1) {
                    nb++;
                }
                if (field[x + 1][y - 1].live == 1) {
                    nb++;
                }
                if (field[x][y - 1].live == 1) {
                    nb++;
                }
                if (field[x - 1][y - 1].live == 1) {
                    nb++;
                }
                if (field[x - 1][y].live == 1) {
                    nb++;
                }
                if (field[x - 1][y + 1].live == 1) {
                    nb++;
                }


                {// изменяю состояние клетки, записываю её в массив "actual"
                    if (field[x][y].live == 0 & nb >= 3) {
                        actual[x][y].live = 1;
                    } else if (nb == 3 & field[x][y].live == 1) {
                        actual[x][y].live = 1;
                    } else if (nb == 2 & field[x][y].live == 1) {
                        actual[x][y].live = 1;
                    } else
                        actual[x][y].live = 0;
                }

                nb = 0;

                x++;
            }

            y++;
        }


        field[X][Y] = actual[X][Y]; //переписываю актуальные значения для каждой клетки в рабочий массив "field"

        //здесь будет создание bmp-шки
        {  // создаю заголовок файла
            unsigned char header[54] = {
                    0x42, 0x4D, // определяю файл как bmp
                    0, 0, 0, 0,
                    0x00, 0x00,
                    0x00, 0x00,
                    0x36, 0x00, 0x00, 0x00,
                    0x28, 0x00, 0x00, 0x00,
                    0, 0, 0, 0,
                    0, 0, 0, 0,
                    0x01, 0x00,
                    0x18, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0, 0, 0, 0,
                    0xC4, 0x0E, 0x00, 0x00,
                    0xC4, 0x0E, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00
            };
            int bitmapSize = 3 * X * Y;
            int fileSize = bitmapSize + 54;
            fillHeaderVal(fileSize, 5, header);
            fillHeaderVal(X, 21, header);
            fillHeaderVal(Y, 25, header);
            fillHeaderVal(bitmapSize, 37, header);


            int padding = (4 - ((3 * Y) % 4));
            if (padding == 4) {  // отступы, чтобы ширина каждой строки в байтах была кратна четырём
                padding = 0;
            }

            FILE *fp;
            fp = fopen("test2.bmp", "w");

            for(int i = 0; i < 54; i++) {
                fputc(header[i], fp);
            }


            x=0;
            y=0;
            for(int i = 0; i < (X * Y); i++) {
                if (field[x][y].live==1){
                    fputc(255, fp);
                    fputc(255, fp);
                    fputc(255, fp);
                    x++;
                    if (x==X){
                        x=0;
                        y++;}
                }
                else if (field[x][y].live==0){
                        fputc(0, fp);
                        fputc(0, fp);
                        fputc(0, fp);
                    x++;
                    if (x==X){
                        x=0;
                        y++;}}

                if(((i +1) % Y == 0)   ) {
                    for( int j = 0; j < padding; j++) {
                        fputc(0, fp);
                    }
                }
            }






        }



            d++;
            y = 0;
            x = 0;
        };
    }
