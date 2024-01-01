#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;
using namespace boost::gregorian;
using namespace boost::posix_time;

bool check_date(string d)
{
    try
    {
        date converted_date = from_string(d);
        return true;
    }
    catch (const exception &e)
    {
        return false;
    }
}

bool check_date_time(string d)
{
    try
    {
        ptime converted_date = time_from_string(d);
        return true;
    }
    catch (const exception &e)
    {
        return false;
    }
}