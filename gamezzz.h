#ifndef MENU
#define MENU
double level(char level) {//уровни сложности,т.е. чем сложнее,тем время передвижения змейки на одну позицию меньше
	if (level == 49) return 0.12;
	if (level == 50)return 0.09;
	if (level == 51)return 0.05;
	if (level == 52)return 0.025;
}
bool end_game(int ochki) {
	char restart = 0;//переменная,читающая кнопку,которые нажал человек,который проиграл и направляет на дальнейшее в зависимости от условий
	SetConsoleCursorPosition(hConsole, { 40,40 });
	cout << "к сожалению,вы проиграли(((";
	SetConsoleCursorPosition(hConsole, { 40,41 });
	cout << "ваше количество очков : " << ochki;
	SetConsoleCursorPosition(hConsole, { 40,42 });
	cout << "если хотите начать заново нажмите пробел,иначе-esc";
	restart = _getch();
	while(restart != 32 && restart != 27) {
		restart = _getch();
	}
	if (restart == 32)return 0;
	else return 1;
}
bool pause(double &start,double &end,double &n,char knop) {
	SetConsoleCursorPosition(hConsole, { 80,10 });
	SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));//возращает стандартный цвет,чтобы было видно все в консоли
	cout << "пауза.Нажмите пробел чтобы продолжить";
	SetConsoleCursorPosition(hConsole, { 80,11 });
	cout << "если хотите выйти в меню,нажмите 1";
	SetConsoleCursorPosition(hConsole, { 80,12 });
	cout << "если хотите выйти из игры,нажмите 2";
	while (!(knop == 32||knop==49||knop==50)) {//пока нет нажатия время не идет
		end = 0;
		n = 1;
		start = 0;
		knop = _getch();
	}
	if (knop == 32) {
		start = clock();
		end = clock();
	}
	if (knop == 49) {
		return 1;
	}
	if (knop == 50) {
		SetConsoleCursorPosition(hConsole, { 30,35 });
		exit(0);
	}
	SetConsoleCursorPosition(hConsole, { 80,10 });
	cout << "                                        ";
	SetConsoleCursorPosition(hConsole, { 80,11 });
	cout << "                                        ";
	SetConsoleCursorPosition(hConsole, { 80,12 });
	cout << "                                        ";
	return 0;
}
void menuska(double &speed,bool &reshim) {
	char kekus = 1;
	system("cls");//чистит консоль от всего
	cout << "меню:"<<endl;
	cout << "почитать об авторе-1 или инструкцию-2 перейти к игре-(любая другая кнопка)" << endl;
	kekus = _getch();
	if (kekus == 49)system("avtor.txt");
	if (kekus == 50)system("instruct.txt");
	cout << "выберете уровень сложности 1-легко,2-средне,3-сложно,4-невозможно " << endl;
	kekus = 0;
	while (kekus < 49 || kekus>53) {
		kekus = _getch();
	}
	speed = level(kekus);//ф-ия выбора уровня сложности
	kekus = 0;
	cout << "змейка белая(0) или меняет цвет(1)?" << endl;
	while (kekus != 48 && kekus != 49) {
		kekus = _getch();
	}
	if (kekus == 48)reshim = false;
	else reshim = true;
	kekus = 0;
	cout << "пауза-esc,если готовы начать нажмите на любую кнопку" << endl;
	cout << "после нажатия змейка появится через 1 секунду и сразу начнет двигаться!будьте к этому готовы!нажмите пробел чтобы начать";
	while (kekus != 32) {
		kekus = _getch();
	}//пока не будет нажат пробел,программа не продожит работу 
	system("cls");
}

void GAME(int granix,int graniy,int &ochki,int razmer,bool reshim,double speed,double n,bool &lose,bool &pas) {
	pole pole(granix, graniy);//конструктор,рисует поле игры
	vector <char> knopka(razmer);//вектор действий на каждый элемент змейки,который зависит от нажатий
	vector <zmeiuka> zmeka(razmer);//вектор класса каждого элемента змейки
	COORD cord;//координаты последнего(стирающего)элемента змейки
	int cvet;//цвет змейки
	char prov1 = 72, prov2;//2 переменные для проверок на нажатие ненправильной кнопки
	eda metka;//"еда" змейки
	//позиция метки(абсолютно случайная,но находящаяся в поле
	metka = metka.generation_metka(granix, graniy);
	for (int i = 0; i < razmer; i++) {
		zmeka[i].sozdanie(i, knopka, razmer);
	}
	double start = clock(), end = clock();//переменные засекающие время
	double	t = (end - start) / CLOCKS_PER_SEC;//t,переводящее время в секунды
	while (!lose) {//пока не проиграл
		t = (end - start) / CLOCKS_PER_SEC;//переменная,засекающая каждый раз прошедшее время после выполнения одного оборота цикла
		cord = zmeka[razmer - 1].pos;
		end = clock();
		SetConsoleCursorPosition(hConsole, { 0,0 });
		if (_kbhit()) {//если произошло нажатие
			knopka[0] = _getch();
		}
		if ((knopka[0] == 27) && prov1 != knopka[0]) {//если человек захочет нажать на паузу
			pas=pause(start, end, n, knopka[0]);
			if (pas)break;
		}
		if (knopka[0] != 75 && knopka[0] != 77 && knopka[0] != 80 && knopka[0] != 72) {//создаю нереагирование на другие кнопки(сверху еще esc))
			knopka[0] = prov1;
		}
		prov1 = knopka[0];//запоминаю для проверки
		prov2 = knopka[razmer - 1];//запоминаю для того,что если мы съедим "еду",то увеличилась бы змейка нормально 
		if ((t > n)) {//если таймер больше прошедшего времени
			if (reshim == 1) {//меняет цвет
				cvet = rand() % 15 + 1;
				SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | cvet));
			}
			vse_deistv(razmer, knopka, zmeka);
			SetConsoleTextAttribute(hConsole, (WORD)((0 << 4) | 15));
			if (knopka[0] == 75 || knopka[0] == 77) {
				n = n + speed;
			}
			else n = n + speed * 2;
			metka.ciela(zmeka, knopka, razmer, prov2, granix, graniy, ochki, cord);
			zmeka[razmer - 1].ris = ' ';
			for (int i = razmer - 1; i > 0; i--) {//передвигает действия на одну позицию назад
				knopka[i] = knopka[i - 1];
			}
		}
		//дальше проверяет врезалась ли змейка куда-либо
		lose = pole.prov(zmeka[0].pos);
		if (lose == false) {
			lose = zmeka[0].prov(zmeka, razmer);
		}
	}
}
#endif 