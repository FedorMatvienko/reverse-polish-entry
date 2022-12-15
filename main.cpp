#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace iss
{
    bool findOperator( string s)
    {
        if ( s == ")" ) return true;
        if ( s == "(" ) return true;
        if ( s == "<" || s == ">" || s == "<=" || s == ">=" ) return true;
        if ( s == "==" || s == "!=" ) return true;
        if ( s == "&&" ) return true;
        if ( s == "||" ) return true;
        if ( s == "-" || s == "+" ) return true;
        return false;
    }
    unsigned int priority( string s )
    {
        if ( s == ")" ) return 1;
        if ( s == "(" ) return 0;
        if ( s == "<" || s == ">" || s == "<=" || s == ">=" ) return 8;
        if ( s == "==" || s == "!=" ) return 9;
        if ( s == "&&" ) return 13;
        if ( s == "||" ) return 14;
        if ( s == "-" || s == "+" ) return 15;
        return 0;
    }
    bool findChar( const char c )
    {
        if ( c == '<' ) return true;
        if ( c == '>' ) return true;
        if ( c == '=' ) return true;
        if ( c == '|' ) return true;
        if ( c == '&' ) return true;
        if ( c == '(' ) return true;
        if ( c == ')' ) return true;
        if ( c == '-' ) return true;
        if ( c == '+' ) return true;
        return false;
    }
}
class pars
{
public:
    string command;
    unsigned int icommand;
    pars(string _command,unsigned int _icommand)
    {
        command = _command;
        icommand = _icommand;
    }
};
//reverse polish entry - обратная польская запись
int main()
{
    string inStr = "a<10&&b > (-10) || ( a == 10 && b == 10)";
    string str = inStr + " ";
    string newStr;
    vector<pars> stack;
    string buf;
    string name;
    bool sign;

    for ( int i = 0; i < str.size(); ++i )
    {
        if ( iss::findOperator(buf) )
        {
            stack.push_back(pars(buf,iss::priority(buf)));
            buf.clear();
        }
        if ( iss::findChar(str[i]) )
        {
            buf += str[i];
            if ( !name.empty() )
            {
                newStr = newStr + name + " ";
                name.clear();
            }
        }
        else if ( str[i] != ' ' )
        {
            name += str[i];
        } 
    }

    //Печать
    for ( auto s: stack )
    {
        cout << s.icommand << " " << s.command << endl;
    }
    cout << newStr << endl;
    return 0;
}