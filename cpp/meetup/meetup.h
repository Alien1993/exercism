#pragma once

#include "boost/date_time/gregorian/gregorian.hpp"

using namespace boost;

namespace meetup {

    class scheduler {
        public:
            scheduler(gregorian::months_of_year month, int year)
                : m_month{month}
                , m_year{year}
            {

            }

            const gregorian::date teenth(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 13};
                while (date.day_of_week() != day) {
                    date += gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date first(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 1};
                while (date.day_of_week() != day) {
                    date += gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date second(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 1};
                int count = 0;
                while (count != 2) {
                    if (date.day_of_week() == day) {
                        count++;
                        if (count == 2) {
                            break;
                        }
                    }
                    date += gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date third(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 1};
                int count = 0;
                while (count != 3) {
                    if (date.day_of_week() == day) {
                        count++;
                        if (count == 3) {
                            break;
                        }
                    }
                    date += gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date fourth(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 1};
                int count = 0;
                while (count != 4) {
                    if (date.day_of_week() == day) {
                        count++;
                        if (count == 4) {
                            break;
                        }
                    }
                    date += gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date last(gregorian::greg_day day) const
            {
                gregorian::date date{m_year, m_month, 1};
                date = date.end_of_month();
                while (date.day_of_week() != day) {
                    date -= gregorian::date_duration(1);
                }
                return date;
            }

            const gregorian::date monteenth()       const { return teenth(gregorian::Monday);       }
            const gregorian::date tuesteenth()      const { return teenth(gregorian::Tuesday);      }
            const gregorian::date wednesteenth()    const { return teenth(gregorian::Wednesday);    }
            const gregorian::date thursteenth()     const { return teenth(gregorian::Thursday);     }
            const gregorian::date friteenth()       const { return teenth(gregorian::Friday);       }
            const gregorian::date saturteenth()     const { return teenth(gregorian::Saturday);     }
            const gregorian::date sunteenth()       const { return teenth(gregorian::Sunday);       }

            const gregorian::date first_monday()    const { return first(gregorian::Monday);    }
            const gregorian::date first_tuesday()   const { return first(gregorian::Tuesday);   }
            const gregorian::date first_wednesday() const { return first(gregorian::Wednesday); }
            const gregorian::date first_thursday()  const { return first(gregorian::Thursday);  }
            const gregorian::date first_friday()    const { return first(gregorian::Friday);    }
            const gregorian::date first_saturday()  const { return first(gregorian::Saturday);  }
            const gregorian::date first_sunday()    const { return first(gregorian::Sunday);    }

            const gregorian::date second_monday()    const { return second(gregorian::Monday);    }
            const gregorian::date second_tuesday()   const { return second(gregorian::Tuesday);   }
            const gregorian::date second_wednesday() const { return second(gregorian::Wednesday); }
            const gregorian::date second_thursday()  const { return second(gregorian::Thursday);  }
            const gregorian::date second_friday()    const { return second(gregorian::Friday);    }
            const gregorian::date second_saturday()  const { return second(gregorian::Saturday);  }
            const gregorian::date second_sunday()    const { return second(gregorian::Sunday);    }

            const gregorian::date third_monday()    const { return third(gregorian::Monday);    }
            const gregorian::date third_tuesday()   const { return third(gregorian::Tuesday);   }
            const gregorian::date third_wednesday() const { return third(gregorian::Wednesday); }
            const gregorian::date third_thursday()  const { return third(gregorian::Thursday);  }
            const gregorian::date third_friday()    const { return third(gregorian::Friday);    }
            const gregorian::date third_saturday()  const { return third(gregorian::Saturday);  }
            const gregorian::date third_sunday()    const { return third(gregorian::Sunday);    }

            const gregorian::date fourth_monday()    const { return fourth(gregorian::Monday);    }
            const gregorian::date fourth_tuesday()   const { return fourth(gregorian::Tuesday);   }
            const gregorian::date fourth_wednesday() const { return fourth(gregorian::Wednesday); }
            const gregorian::date fourth_thursday()  const { return fourth(gregorian::Thursday);  }
            const gregorian::date fourth_friday()    const { return fourth(gregorian::Friday);    }
            const gregorian::date fourth_saturday()  const { return fourth(gregorian::Saturday);  }
            const gregorian::date fourth_sunday()    const { return fourth(gregorian::Sunday);    }

            const gregorian::date last_monday()    const { return last(gregorian::Monday);    }
            const gregorian::date last_tuesday()   const { return last(gregorian::Tuesday);   }
            const gregorian::date last_wednesday() const { return last(gregorian::Wednesday); }
            const gregorian::date last_thursday()  const { return last(gregorian::Thursday);  }
            const gregorian::date last_friday()    const { return last(gregorian::Friday);    }
            const gregorian::date last_saturday()  const { return last(gregorian::Saturday);  }
            const gregorian::date last_sunday()    const { return last(gregorian::Sunday);    }

        private:
            gregorian::months_of_year m_month;
            int m_year;
    };
}