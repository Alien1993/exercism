#pragma once

#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond {
    const ptime advance(ptime birthDate)
    {
        return birthDate + seconds(1) * 1000000000;
    }
}