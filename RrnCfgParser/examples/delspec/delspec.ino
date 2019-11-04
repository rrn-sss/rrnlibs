#include <RrnCfgParser.h>

/*
  парсинг строки
  "{[password] = 12345678}"

  результат работы парсера будет сохранен в двух строках
  parname = "password"          // удалены все спец-символы
  parval  = "12345678"          // и пробелы
*/

using namespace rrnlibs;

RrnCfgParser parser; // создаем парсер

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String srcstr = "{[password] = 12345678}"; // входная строка для парсера
  String parname, parval; // здесь будут сохранены результаты выполнения парсера (имя параметра и значение параметра)
  
  // настройки парсера
  parser.setDelimiter('=');
  parser.setEnding('\n');
  parser.setTrim(true);  
  parser.delSpec(true);  

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
