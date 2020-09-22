
## Switch-Case Control Statement :
- her switch-case --> if-else dönüştürülebilir. Ancak tersi her zaman doğru değil!
- daha iyi compiler optimization için tercih edilebilir.
- switch() blok içindeki ifade tamsayı türü olmak zorundadır (double, float vb. olamaz).
- case label ise constant tamsayı değeri olmak zorundadır !!! Değişken veya real sayılardan biri olamaz.  
- her bir case label unique olmalıdır. 
- break; kullanımı, case geçişleri arasında yaygındır (break; deyiminin özellikle kullanılmak zorunda olmadığı diller de mevcut!!!)
- case label sonrasında mutlaka bir ifade bulunmalıdır. 
- default case, switch-case ifadesinin farklı yerlerde bulunması anlam açısından fark yaratmaz. Ancak okunabilirlik açısından sonda bulunması tercih edilir. 
- The usage of case labels: 
  - case 'A':        --> OK
  - case "Jane":     --> NOT OK, the case label shall not be string literal 
  - case 12.5:       --> NOT OK, the case label shall be integer value
  - case MAX:        --> OK or NOT OK, it depends on MAX value
  - case (MIN+MAX)/2:--> OK or NOT OK, it depends on MAX, MIN values
  - case -5:	     --> OK, the case label can be positive or negative integer values 
  - case 0X23:       --> OK, the case label can be defined in a different number systems

/----------------------------------------------
/----------------------------------------------

```cpp
switch (x) {
case 5,4,3,2,1 :printf("hello");        // syntax error
}

switch (x) {
case 5; case 4; case 3:printf("hello"); // not syntax error
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x = 3;
	
	switch (x) {
	case 4 :
	case 3 :
	case 2 : printf("hello"); // syntax error
	case 1 :
	}
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
	int x; 
	switch (x)
		case 1 :printf("hello"); 
		// This style can be used, but not preferable!
		// Instead of using this style, use if-else block! 
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Using if-else block instead of switch-case block 

```cpp
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {

	int day_order;
	
	printf("1 : Monday    \n");
	printf("2 : Tuesday   \n");
	printf("3 : Wednesday \n");
	printf("4 : Thursay   \n");
	printf("5 : Friday    \n");
	printf("6 : Saturday  \n");
	printf("7 : Sunday    \n\n");
	printf("What is the order of the selected day in a week ?: ");
	scanf("%d", &day_order);

	if (day_order == 1) 
		printf("Monday\n");
	else if (day_order == 2) 
		printf("Tuesday\n");
	else if (day_order == 3) 
		printf("Wednesday\n");
	else if (day_order == 4) 
		printf("Thursay\n");
	else if (day_order == 5)
		printf("Friday\n");
	else if (day_order == 6)
		printf("Saturday\n");
	else if (day_order == 7)
		printf("Sunday\n");
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Using switch-case block instead of if-else block 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {

	int day_order;
	
	printf("1 : Monday    \n");
	printf("2 : Tuesday   \n");
	printf("3 : Wednesday \n");
	printf("4 : Thursay   \n");
	printf("5 : Friday    \n");
	printf("6 : Saturday  \n");
	printf("7 : Sunday    \n\n");
	printf("What is the order of the selected day in a week ?: ");
	
	scanf("%d", &day_order);

	switch (day_order) {
	case 1:printf("Monday    \n"); break; 
	case 2:printf("Tuesday   \n"); break;
	case 3:printf("Wednesday \n"); break;
	case 4:printf("Thursay   \n"); break;
	case 5:printf("Friday    \n"); break;
	case 6:printf("Saturday  \n"); break;
	case 7:printf("Sunday    \n"); break;
	default:printf("Invalid Day Selection!!!\n"); break; 
	}
	
	return 0;
}
```

/----------------------------------------------
/----------------------------------------------

- Example: Printing "hello" without using semi-colon (Interview Question) 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>

int main() {
	switch (printf("hello")) {}
}
```

/----------------------------------------------

- Example: Printing "hello" by using switch-case block (another solution type for the previous example)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x = 5;
	switch (x) {
	case 5 :printf("hello");
	}
}
```

/----------------------------------------------
/----------------------------------------------

- Example: Desingning the following cases with the same results  
  - case 12, case 1, case 2  --> printing "Winter"
  - case 3, case 4, case 5   --> printing "Spring"
  - case 6, case 7, case 8   --> printing "Summer"
  - case 9, case 10, case 12 --> printing "Autumn"

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int month_order = 3;

	switch (month_order) {
	case 12:
	case 1:
	case 2:printf("Winter \n"); break;
	case 3:
	case 4:
	case 5:printf("Spring \n"); break;
	case 6:
	case 7:
	case 8:printf("Summer \n"); break;
	case 9:
	case 10:
	case 11:printf("Autumn \n"); break;
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Printing the season names with if-else and switch-case blocks 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_season_switch(int month) {
	
	switch (month) {
	case 12:
	case 1:
	case 2:printf("Winter \n"); break;
	case 3:
	case 4:
	case 5:printf("Spring \n"); break;
	case 6:
	case 7:
	case 8:printf("Summer \n"); break;
	case 9:
	case 10:
	case 11:printf("Autumn \n"); break;
	default:printf("Invalid Season Selection!!!\n"); break;
	}
}

void print_season_if(int month) {

	if(month == 12 || month == 1 || month == 2 )
		printf("Winter\n");
	else if(month == 3 || month == 4 || month == 5)
		printf("Spring\n");
	else if (month == 6 || month == 7 || month == 8)
		printf("Summer\n");
	else if (month == 9 || month == 10 || month == 11)
		printf("Autumn\n");
	else
		printf("Invalid Season Selection!!!\n");

}

int main() {

	int month = 0;
	
	printf("12,1,2  : Winter \n");
	printf("3,4,5   : Spring \n");
	printf("6,7,8   : Summer \n");
	printf("9,10,11 : Autumn \n\n");
	printf("What is the order of the selected month ? : ");
	
	scanf("%d", &month);

	print_season_switch(month);
	print_season_if(month);
}
```

/----------------------------------------------
/----------------------------------------------

- Example: Writing "fallthrough" comment in switch-case blocks 
  - While "fallthrough" comment is written, it means that the faulty case is realized consciously. 
  - Normally, static code analyser tools (SonarQube, etc.) return a warning message for this kind of cases which not having break statement. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int x = 3;

	switch (x) {
	case 1: statement1;  // fallthrough
	case 2: statement2; break; 
	//...
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Using switch - case blocks with macros

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Macro Definitions
#define OFF       0 
#define ON        1
#define STAND_BY  2
#define HOLD      3

int main() {

	int state = 0;

	printf("0 : OFF State      \n");
	printf("1 : ON State       \n");
	printf("2 : STAND_BY State \n");
	printf("3 : HOLD State     \n\n");
	printf("What is the selected state ? (0/1/2/3): ");

	scanf("%d", &state);

	switch (state) {
	case OFF     : printf("OFF State"); break;
	case ON      : printf("ON State"); break;
	case STAND_BY: printf("STAND_BY State"); break;
	case HOLD    : printf("HOLD State"); break;
	default      : printf("Invalid State Selection"); break;
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Using switch - case blocks with enumeration (1)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Enumeration Definitions --> Underlined Type: int
enum State {
	OFF,
	ON,
	STAND_BY,
	HOLD
};

int main() {

	enum State state = OFF;

	printf("0 : OFF State      \n");
	printf("1 : ON State       \n");
	printf("2 : STAND_BY State \n");
	printf("3 : HOLD State     \n\n");
	printf("What is the selected state ? (0/1/2/3): ");

	scanf("%d", &state);

	switch (state) {
	case OFF     : printf("OFF State"); break;
	case ON      : printf("ON State"); break;
	case STAND_BY: printf("STAND_BY State"); break;
	case HOLD    : printf("HOLD State"); break;
	default      : printf("Invalid State Selection"); break;
	}
}
```

/----------------------------------------------
/----------------------------------------------

- Example: Using switch - case blocks with enumeration (2)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum Card {
	Club,
	Diamond,
	Heart,
	Spade
};

int main() {

	enum Card suit = Club;

	printf("0 : Club Card      \n");
	printf("1 : Diamond Card   \n");
	printf("2 : Heart Card	   \n");
	printf("3 : Spade Card     \n\n");
	printf("What is the selected card ? (0/1/2/3): ");

	scanf("%d", &suit);

	switch (suit) {
	case Club   : printf("Club Selected!!!"); break;
	case Diamond: printf("Diamond Selected!!!"); break;
	case Heart  : printf("Heart Selected!!!"); break;
	case Spade  : printf("Spade Selected!!!"); break;
	default     : printf("Invalid Card Selection!!!"); break;
	}
}
```

/----------------------------------------------
/----------------------------------------------

- Example: 
  - Printing the day of the selected date with functions including switch-case blocks
  - Considering the following specification: 
    - The suffix is : st --> 1st  June 2020, 21st June 2020, 31st June 2020
    - The suffix is : nd --> 2nd  August 2020, 22nd August 2020 
    - The suffix is : rd --> 3rd  September 2020, 23rd September 2020
    - The suffix is : th (the other days) --> 15th, 14th, 16th, 17th, 18th, 19th,... May 2020

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

void print_date(int day, int month, int year) {

	printf("%02d", day); // 0 is the filling charachter here

	switch (day) {
	case 1:
	case 21:
	case 31: printf("st "); break;
	case 2:
	case 22: printf("nd "); break;
	case 3:
	case 23: printf("rd "); break;
	default: printf("th "); break;
	}

	switch (month) {
	case 1:  printf("January "); break;
	case 2:  printf("February "); break;
	case 3:  printf("March "); break;
	case 4:  printf("April "); break;
	case 5:	 printf("May "); break;
	case 6:  printf("June "); break;
	case 7:  printf("July "); break;
	case 8:  printf("August "); break;
	case 9:  printf("September "); break;
	case 10: printf("October "); break;
	case 11: printf("November "); break;
	case 12: printf("December "); break;
	default: printf("Invalid Month Selection !!!"); break;
	}

	printf("%d", year);
}

int main() {
	int day = 0;
	int month = 0;
	int year = 0;

	while (SIZE != 0) {
		printf("What is the date (day/month/year)? : ");
		scanf("%d%d%d", &day, &month, &year);

		print_date(day, month, year);
		putchar('\n');
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Printing the day of weeks with switch-case blocks and random number generators

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < 20; ++i) {
		switch (rand() % 7 + 1){
		case 1: printf("Monday \n"); break;
		case 2: printf("Tuesday \n"); break;
		case 3: printf("Wednesday \n"); break;
		case 4: printf("Thursday \n"); break;
		case 5: printf("Friday \n"); break;
		case 6: printf("Saturday \n"); break;
		case 7: printf("Sunday \n"); break;
		}
		_getch();
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Finding the day of year with switch-case 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define isleap(y)  ((y)%4 == 0 && ((y)%100 != 0 || (y)%400 ==0))
#define SIZE 5 

int is_leap_year(int year) {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int day_of_year(int day, int month, int year) {
	
	int sum = day;

	switch (month-1) {
	case 11: sum += 30; // fallthrough
	case 10: sum += 31; // fallthrough
	case 9: sum += 30;  // fallthrough
	case 8: sum += 31;  // fallthrough
	case 7: sum += 31;  // fallthrough
	case 6: sum += 30;  // fallthrough
	case 5: sum += 31;  // fallthrough
	case 4: sum += 30;  // fallthrough
	case 3: sum += 31;  // fallthrough
	case 2: sum += 28 + is_leap_year(year);  // fallthrough
	//case 2: sum += isleap(year) ? 28 : 29; // fallthrough
	case 1: sum += 31;  // fallthrough
	}

	return sum;
}

int main() {

	int day = 0;
	int month = 0;
	int year = 0;

	while (SIZE != 0) {
		printf("What is the date (day/month/year)? : ");
		scanf("%d%d%d", &day, &month, &year);
		
		int dayOfYear = day_of_year(day, month, year);
		printf("The day of year : %d", dayOfYear);
		
		putchar('\n');
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: A pseudo code example with switch-case block 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define OFF      0 
#define ON       1 
#define STAND_BY 2 
#define HOLD     3 

int is_remote_access() { return 1; }
void off_state(void) {}
void on_state(void) {}
void standby_state(void) {}
void hold_state(void) {}
void default_state(void) {}

int main() {

	switch (is_remote_access()) {
	case 0 : off_state(); break;
	case 1 : on_state(); break;
	case 2 : standby_state(); break;
	case 3 : hold_state(); break;
	default: default_state() ; break;
	}
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Printig selected value with switch-case block

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 

typedef enum {
	COLOR_BLACK,
	COLOR_WHITE, 
	COLOR_PURPLE,
	COLOR_YELLOW,
	COLOR_GREEN
}Colors;

void print_color(Colors color) {

	switch (color) {
	case COLOR_BLACK  : printf("Black\n"); break;
	case COLOR_WHITE  : printf("White\n"); break;
	case COLOR_PURPLE : printf("Purple\n"); break;
	case COLOR_YELLOW : printf("Yellow\n"); break;
	case COLOR_GREEN  : printf("Green\n"); break;
	default: printf("Invalid Color Selection\n"); break;
	}
}

int main() {

	Colors color = COLOR_BLACK; 

	while (SIZE != 0) {

		printf("0 : Black   \n");
		printf("1 : White   \n");
		printf("2 : Purple  \n");
		printf("3 : Yellow  \n");
		printf("4 : Green   \n\n");
		printf("What is the selected card ? (0/1/2/3/4): ");

		scanf("%d", &color);
		print_color(color);
		putchar('\n');
	}
}
```

/----------------------------------------------
/----------------------------------------------
