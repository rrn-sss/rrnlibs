#include "RrnCfgParser.h"

namespace rrnlibs
{

RrnCfgParser::RrnCfgParser()
{
  reset();
  
  _f_del  = 
  _f_trim = false;
}

/* конструктор конфигурационного парсера */
RrnCfgParser::RrnCfgParser(char delim, bool trim /*= false*/, char ending /*= '\n'*/)
{
  reset();
  _f_del  = false;
  _f_trim = trim;
  _delim  = delim;
  _ending = ending;
}

/* сбрасывает значен€и по-умолчанию в качестве значени€ внутренних переменных*/
void RrnCfgParser::reset() 
{
  _parname  = 
  _parval   =   
  _tmpinstr = "";
}

/* парсит строку и возвращает им€ отпарсенного параметра и его значение в
   случае успеха	
*/
bool RrnCfgParser::getParam(String &instr, String *name, String *value)
{
  int     pos_d, pos_e;
  bool    ret = false;
  String  str = instr;
  
  if( str.length() <= _max_instring_len_ && name && value )
  {  
    // удаляем спец символы, если заказано // TODO CHECK !!!
    if(_f_del)
    {
      for(pos_d = 0; pos_d < str.length(); )
      {
	   char chr = str.charAt(pos_d);
	   bool endchar = chr == _ending || chr == '\n' || chr == '\r' || chr == '\0';
       if(((chr < '0' || chr > '9') && 
        (chr < 'A' || chr > 'Z') &&
        (chr < 'a' || chr > 'z'))&&
        chr != _delim && !endchar)
	      str.remove(pos_d, 1);        
		else 
	      pos_d++;
      }
    }

    // если заказано, то уберем из строки пробелы
    if( _f_trim )
      str.trim();
    
    pos_d = str.indexOf(_delim);
    if( pos_d > 0)
    {
      _parname = str.substring(0, pos_d);
      pos_e = str.indexOf(_ending);          
      if( pos_e > 2 )
        _parval  = str.substring(pos_d+1, pos_e);
      else
        _parval  = str.substring(pos_d+1);
      
      _parname.trim();
      _parval.trim();
    
      if( _parname.length() > 0 && _parval.length() > 0 )
      {
        *name   = _parname;
        *value  = _parval;
        
        reset();
        ret = true;
      }
    }
  }
  
  return ret;
}

/* добавл€ет символ в строку дл€ парсинга и возвращает им€ отпарсенного 
   параметра и его значение в случае успеха	
*/
bool RrnCfgParser::getParam(char inchr, String *name, String *value)
{
  bool ret  = false;
  bool skip = false; 
  bool endchar = inchr == _ending || inchr == '\n' || inchr == '\r' || inchr == '\0';
  
  if( _tmpinstr.length() >= _max_instring_len_)
    reset();

  // удал€ем спец символы, если заказано // TODO CHECK !!!
  if(_f_del)
  {  
    if(((inchr < '0' || inchr > '9') && 
        (inchr < 'A' || inchr > 'Z') &&
        (inchr < 'a' || inchr > 'z'))&&
        inchr != _delim && !endchar)
    skip = true;
  }

  if(_f_trim && inchr == ' ')
    skip = true;

  if( !skip )    
  {
    if( endchar )
      ret = getParam( _tmpinstr, name, value );     
    else
      _tmpinstr += inchr;
  }
    
  return ret;
}

/* установить/сбросить признак тиммировани€ строк */
void RrnCfgParser::setTrim(bool trim)
{
  _f_trim = true;
}

/* установить символ-разделитель имени параметра от его значени€ */
void RrnCfgParser::setDelimiter(char delim)
{
  _delim = delim;
}

/* установить символ окончани€ строки дл€ парсинга */
void RrnCfgParser::setEnding(char ending)
{
  _ending = ending;
}

/* устанавливает признак необходимости удалени€ всех символов не 
   €вл€ющихс€ цифрами, буквами, и символами разделител€ и конца строки */

void RrnCfgParser::delSpec(bool delspec)
{
  _f_del = delspec;
}

} // namespace 