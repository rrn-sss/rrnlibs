#ifndef _CPARSER_H_ 
#define _CPARSER_H_ 

#include <Arduino.h>

/**
\namespace rrnlibs 
\brief namespace ��������� rrn
*/
namespace rrnlibs
{

#define _max_instring_len_ (255) //!< ������������ ����� ������� ������

/*! 
  \class RrnCfgParser
  \brief ������ ���������������� �����
  \note 
*/
class RrnCfgParser
{
  public:
  /*! @brief ����������� ����������������� ������� */
  RrnCfgParser();
  
  /*! @brief ����������� ����������������� ������� 
  \param [in] trim ������� ������������� �������� �������� �� ����� ���������
           � �� ��� ��������
  \param [in] delim ������ ����������� ����� ��������� � �������� ���������
  \param [in] ending ������ ���������� �������� ���������	    
	*/
  RrnCfgParser(char delim, bool trim = false, char ending = '\n');
 	
  /*! @brief ������ ������ � ���������� ��� ������������ ��������� � ��� �������� �
  	������ ������	
  \param [in] instr ������� ������ ��� ��������
  \param [out] name ��� ������������� ���������
  \param [out] value �������� ������������� ���������
  \return ������� ����������  ���������� ������� (true ���� ������ ��������
  ��� � �������� ���������)
  */
  bool getParam(String &instr, String *name, String *value);	
	
  /*! @brief ��������� ������ � ������ ��� �������� � ���������� ��� ������������ 
      ��������� � ��� �������� � ������ ������	
  \param [in] inchr ������ ����������� � ������ ��� ��������
  \param [out] name ��� ������������� ���������
  \param [out] value �������� ������������� ���������
  \return ������� ���������� (true ���� ������ �������� ��� � ��������
       	���������)
  */
  bool getParam(char inchr, String *name, String *value);	

  /*! @brief ����������/�������� ������� ������������ ����� 
  \param [in] trim ������� ������������� (true - ������������ ������)
  */
  void setTrim(bool trim);

  /*! @brief ���������� ������-����������� ����� ��������� �� ��� ��������
  \param [in] delim ������-�����������
  */
  void setDelimiter(char delim);

  /*! @brief ���������� ������ ��������� ������ ��� ��������
  \param [in] end ������ ��������� ������
  */
  void setEnding(char ending);

  /*! @brief ������������� ������� ������������� �������� ���� �������� �� 
             ���������� �������, �������, � ��������� ����������� � ����� ������
  \param [in] delspec ������� �������������� �������� ���� ��������
  */
  void delSpec(bool delspec); 
	
  protected:
  /*! @brief ���������� �������� ��-��������� � �������� �������� ���������� ����������*/
    void reset();
    
  private:
    String _parname;  //!< ��� ��������� 
    String _parval;   //!< �������� ��������� 
    String _tmpinstr; //!< ���������� ������ ��� ������������� ���������� ������� ������
    bool   _f_trim;   //!< ������� ������������� ������������� �����
    bool   _f_del;    //!< ������� ������������� �������� ���� �������� �� �����
    char   _delim;    //!< ������-����������� ����� ��������� � �������� ���������
    char   _ending;   //!< ������ ���������� ������ ���������� �������� � ��� ��������
};
} // namespace rrnlibs

#endif
