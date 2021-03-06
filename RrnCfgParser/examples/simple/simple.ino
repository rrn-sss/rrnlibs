#include <RrnCfgParser.h>

/*
  парсинг строки
  "password = 12345678"

  результат работы парсера будет сохранен в двух строках
  parname = "password "          // пробелы не удаляются, т.к. при создании парсера не был задан параметр trim=true
  parval  = " 12345678"
*/


using namespace rrnlibs;

RrnCfgParser parser('='); // создаем парсер, без удаления лишних пробелов, работает до конца строки

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String srcstr = "password = 12345678"; // входная строка для парсера
  String parname, parval; // здесь будут сохранены результаты выполнения парсера (имя параметра и значение параметра)
  

  // парсинг строки srcstr в две строки parname (имя параметра) и parval (значение параметра)
  parser.getParam(srcstr, &parname, &parval);  

  Serial.println("исходная строка    :"+String(srcstr));
  Serial.println("результат парсера:");
  Serial.println("имя параметра      :"+String(parname));
  Serial.println("значение параметра :"+String(parval));


  do 
  {
    ; // бесконечный пустой цикл
  } while(1);
}
