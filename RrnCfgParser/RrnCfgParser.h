#ifndef _CPARSER_H_ 
#define _CPARSER_H_ 

#include <Arduino.h>

/**
\namespace rrnlibs 
\brief namespace библиотек rrn
*/
namespace rrnlibs
{

#define _max_instring_len_ (255) //!< максимальная длина входной строки

/*! 
  \class RrnCfgParser
  \brief Парсер конфигурационных строк
  \note 
*/
class RrnCfgParser
{
  public:
  /*! @brief конструктор конфигурационного парсера */
  RrnCfgParser();
  
  /*! @brief конструктор конфигурационного парсера 
  \param [in] trim признак необходимости удаления пробелов из имени параметра
           и из его значения
  \param [in] delim символ разделителя имени параметра и значения параметра
  \param [in] ending символ завершения значения параметра	    
	*/
  RrnCfgParser(char delim, bool trim = false, char ending = '\n');
 	
  /*! @brief парсит строку и возвращает имя отпарсенного параметра и его значение в
  	случае успеха	
  \param [in] instr входная строка для парсигна
  \param [out] name имя возвращаемого параметра
  \param [out] value значение возвращаемого параметра
  \return признак успешности  завершения функции (true если строка содержит
  имя и значение параметра)
  */
  bool getParam(String &instr, String *name, String *value);	
	
  /*! @brief добавляет символ в строку для парсинга и возвращает имя отпарсенного 
      параметра и его значение в случае успеха	
  \param [in] inchr символ добавляемый в строку для парсинга
  \param [out] name имя возвращаемого параметра
  \param [out] value значение возвращаемого параметра
  \return признак успешности (true если строка содержит имя и значение
       	параметра)
  */
  bool getParam(char inchr, String *name, String *value);	

  /*! @brief установить/сбросить признак тиммирования строк 
  \param [in] trim признак триммирования (true - триммировать строки)
  */
  void setTrim(bool trim);

  /*! @brief установить символ-разделитель имени параметра от его значения
  \param [in] delim символ-разделитель
  */
  void setDelimiter(char delim);

  /*! @brief установить символ окончания строки для парсинга
  \param [in] end символ окончания строки
  */
  void setEnding(char ending);

  /*! @brief устанавливает признак необходимости удаления всех символов не 
             являющихся цифрами, буквами, и символами разделителя и конца строки
  \param [in] delspec признак неообходимости удаления спец символов
  */
  void delSpec(bool delspec); 
	
  protected:
  /*! @brief сбрасывает значеняи по-умолчанию в качестве значения внутренних переменных*/
    void reset();
    
  private:
    String _parname;  //!< имя параметра 
    String _parval;   //!< значение параметра 
    String _tmpinstr; //!< внутренняя строка для посимвольного накопления входной строки
    bool   _f_trim;   //!< признак необходимости триммирования строк
    bool   _f_del;    //!< признак необходимости удаления спец символов из строк
    char   _delim;    //!< символ-разделитель имени параметра и значения переметра
    char   _ending;   //!< символ завершения строки содержащей параметр и его значение
};
} // namespace rrnlibs

#endif
