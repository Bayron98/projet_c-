#include "../include/validator.h"

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