float data[2][2000] = {
{1538,2188,1983,2097,2028,2075,2048,2068,2061,2068,2068,2071,2073,2077,2079,2083,2086,2090,2094,2100,2104,2110,2116,2122,2128,2134,2138,2142,2146,2149,2151,2151,2148,2142,2134,2123,2110,2096,2080,2064,2050,2038,2027,2018,2012,2007,2003,1999,1997,1996,1996,1995,1995,1995,1995,1997,1997,1997,1997,1999,1999,2000,2001,2001,2003,2003,2003,2003,2004,2005,2006,2007,2007,2007,2007,2007,2009,2010,2010,2010,2011,2013,2013,2015,2017,2017,2019,2021,2023,2024,2024,2024,2024,2024,2024,2026,2026,2026,2026,2026,2026,2026,2026,2028,2029,2029,2029,2029,2029,2031,2031,2031,2031,2031,2032,2033,2033,2033,2034,2035,2035,2036,2037,2037,2037,2037,2037,2039,2039,2039,2039,2040,2041,2042,2043,2043,2043,2043,2043,2043,2043,2043,2045,2045,2046,2047,2049,2051,2052,2052,2052,2055,2059,2063,2065,2065,2064,2062,2062,2062,2062,2059,2054,2048,2045,2044,2044,2043,2043,2042,2042,2041,2040,2040,2039,2039,2039,2039,2039,2039,2039,2040,2041,2041,2041,2039,2037,2038,2046,2063,2096,2147,2207,2264,2284,2257,2200,2133,2079,2051,2040,2037,2040,2043,2042,2040,2038,2037,2038,2039,2039,2041,2041,2043,2045,2047,2047,2047,2047,2048,2049,2050,2052,2052,2054,2055,2056,2058,2060,2062,2064,2066,2069,2072,2075,2079,2083,2087,2092,2098,2105,2113,2123,2132,2140,2146,2150,2153,2155,2156,2154,2147,2136,2123,2109,2095,2079,2063,2047,2034,2023,2015,2008,2002,1996,1992,1988,1987,1987,1987,1988,1989,1989,1991,1991,1991,1992,1993,1993,1993,1995,1995,1997,1999,2001,2002,2002,2002,2002,2002,2002,2003,2004,2004,2004,2004,2005,2006,2006,2008,2010,2010,2012,2012,2012,2013,2015,2015,2016,2017,2017,2019,2021,2021,2023,2023,2023,2023,2023,2023,2023,2023,2023,2023,2025,2025,2026,2028,2028,2028,2028,2029,2030,2030,2030,2030,2030,2030,2030,2030,2031,2032,2033,2034,2034,2035,2036,2036,2036,2038,2038,2038,2038,2038,2038,2038,2040,2042,2044,2045,2044,2042,2042,2042,2042,2044,2044,2046,2048,2050,2052,2052,2053,2055,2058,2061,2063,2063,2063,2063,2063,2062,2059,2055,2051,2047,2044,2043,2042,2042,2041,2041,2041,2041,2041,2041,2040,2040,2040,2040,2040,2041,2043,2044,2044,2042,2039,2037,2040,2049,2070,2110,2165,2227,2277,2284,2247,2185,2118,2069,2045,2037,2036,2041,2044,2043,2041,2039,2038,2037,2037,2039,2039,2040,2042,2042,2044,2044,2046,2047,2048,2050,2050,2052,2054,2054,2056,2056,2058,2060,2062,2064,2066,2069,2072,2075,2079,2083,2088,2094,2099,2104,2109,2114,2122,2130,2137,2143,2149,2152,2154,2154,2151,2145,2136,2123,2108,2092,2076,2060,2045,2033,2021,2012,2005,1999,1995,1992,1990,1988,1988,1987,1987,1989,1989,1991,1991,1991,1992,1993,1993,1995,1997,1999,2000,2000,2000,2000,2000,2000,2000,2001,2002,2002,2004,2004,2005,2007,2008,2009,2010,2011,2013,2013,2014,2015,2015,2016,2018,2018,2020,2021,2022,2023,2023,2023,2023,2023,2023,2023,2022,2022,2022,2022,2024,2024,2025,2027,2027,2027,2027,2027,2027,2027,2029,2029,2029,2029,2029,2029,2029,2029,2031,2031,2032,2034,2034,2035,2036,2036,2036,2036,2036,2037,2038,2038,2038,2038,2038,2038,2038,2038,2040,2040,2040,2040,2040,2041,2042,2042,2044,2046,2048,2050,2052,2054,2054,2056,2059,2063,2065,2066,2064,2063,2063,2062,2060,2055,2049,2045,2041,2040,2042,2042,2042,2042,2042,2041,2041,2041,2041,2042,2043,2043,2043,2043,2043,2045,2045,2045,2043,2041,2042,2048,2061,2087,2131,2185,2241,2271,2256,2208,2142,2083,2048,2034,2032,2039,2046,2049,2049,2047,2046,2045,2045,2045,2047,2047,2047,2049,2049,2051,2051,2051,2052,2053,2053,2055,2057,2057,2057,2059,2061,2063,2065,2067,2071,2073,2077,2080,2084,2087,2091,2095,2101,2107,2113,2119,2125,2131,2137,2143,2148,2151,2153,2152,2150,2145,2137,2126,2113,2097,2081,2065,2049,2036,2024,2015,2007,1999,1993,1990,1988,1986,1986,1985,1985,1985,1985,1987,1987,1989,1990,1990,1992,1992,1992,1992,1994,1994,1995,1996,1997,1999,2000,2000,2001,2001,2001,2001,2002,2003,2004,2006,2008,2008,2009,2011,2011,2013,2015,2017,2019,2019,2019,2019,2019,2019,2019,2021,2021,2022,2023,2023,2023,2024,2024,2024,2024,2024,2026,2027,2028,2029,2029,2029,2029,2029,2029,2029,2031,2031,2030,2030,2030,2030,2032,2032,2034,2034,2034,2034,2034,2034,2036,2036,2036,2038,2039,2040,2042,2042,2042,2042,2042,2042,2042,2042,2042,2044,2046,2049,2051,2051,2052,2054,2058,2061,2063,2063,2061,2061,2061,2060,2056,2052,2048,2044,2041,2041,2041,2041,2040,2038,2038,2037,2037,2039,2039,2039,2040,2041,2040,2040,2040,2041,2042,2042,2040,2040,2041,2048,2061,2088,2129,2176,2222,2240,2219,2171,2112,2063,2037,2030,2032,2039,2046,2047,2046,2045,2045,2045,2045,2046,2047,2048,2050,2052,2052,2052,2052,2052,2052,2051,2050,2050,2050,2051,2053,2055,2057,2059,2061,2065,2067,2070,2073,2077,2082,2088,2092,2096,2099,2103,2109,2117,2123,2129,2135,2141,2145,2147,2149,2150,2148,2143,2135,2124,2111,2097,2082,2067,2053,2039,2027,2018,2010,2004,1999,1995,1993,1991,1991,1990,1990,1990,1991,1992,1992,1994,1994,1996,1997,1997,1997,1999,1999,2000,2002,2003,2004,2006,2006,2006,2006,2008,2008,2008,2009,2010,2010,2012,2012,2013,2014,2015,2016,2017,2018,2018,2020,2022,2022,2024,2024,2025,2026,2026,2026,2026,2026,2026,2025,2025,2025,2027,2027,2029,2029,2030,2032,2032,2032,2032,2032,2032,2032,2032,2033,2034,2035,2037,2036,2035,2035,2036,2039,2041,2042,2042,2041,2041,2041,2041,2041,2041,2041,2041,2043,2043,2043,2043,2042,2042,2042,2043,2044,2045,2047,2049,2051,2052,2052,2054,2058,2061,2063,2064,2064,2062,2062,2062,2062,2059,2053,2048,2044,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2043,2042,2040,2038,2037,2043,2056,2079,2118,2171,2232,2280,2284,2246,2184,2119,2073,2050,2043,2043,2047,2050,2049,2046,2042,2038,2034,2033,2033,2034,2036,2036,2038,2040,2041,2045,2047,2049,2052,2053,2054,2056,2058,2058,2060,2062,2064,2066,2068,2070,2072,2074,2078,2082,2086,2090,2096,2100,2105,2111,2117,2123,2129,2135,2141,2145,2148,2150,2151,2149,2144,2135,2124,2110,2094,2078,2062,2047,2035,2025,2017,2009,2003,1999,1995,1992,1990,1990,1990,1990,1990,1991,1992,1992,1992,1993,1994,1995,1997,1997,1997,1999,1999,1999,2001,2001,2001,2002,2003,2003,2005,2005,2005,2007,2007,2007,2007,2009,2009,2009,2011,2011,2012,2014,2016,2016,2018,2018,2018,2018,2019,2021,2021,2022,2023,2024,2025,2025,2025,2026,2027,2027,2027,2027,2027,2027,2029,2030,2030,2030,2030,2030,2030,2030,2031,2032,2032,2032,2034,2034,2035,2036,2036,2036,2036,2036,2036,2036,2038,2038,2040,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2043,2045,2047,2049,2050,2050,2051,2053,2057,2061,2063,2064,2063,2062,2062,2062,2060,2056,2050,2044,2041,2040,2040,2040,2040,2040,2040,2040,2040,2039,2039,2039,2040,2040,2041,2042,2043,2045,2044,2042,2038,2036,2037,2045,2058,2082,2125,2182,2245,2287,2283,2239,2173,2107,2064,2045,2039,2040,2045,2048,2048,2048,2047,2046,2046,2045,2045,2047,2047,2047,2049,2050,2050,2050,2050,2050,2052,2052,2054,2054,2056,2056,2058,2060,2062,2064,2066,2068,2068,2071,2075,2079,2083,2089,2094,2099,2105,2113,2119,2125,2132,2138,2144,2148,2150,2152,2151,2148,2143,2134,2121,2106,2088,2070,2052,2037,2024,2013,2004,1998,1992,1987,1985,1983,1981,1981,1981,1981,1981,1982,1983,1983,1983,1983,1985,1985,1986,1988,1990,1990,1990,1990,1990,1991,1993,1993,1994,1995,1995,1997,1998,1998,2000,2001,2002,2004,2005,2006,2008,2008,2010,2012,2012,2014,2014,2014,2015,2016,2017,2018,2018,2018,2020,2020,2020,2020,2020,2020,2021,2022,2023,2025,2025,2025,2025,2027,2027,2027,2029,2029,2029,2029,2029,2031,2031,2033,2033,2033,2033,2033,2033,2035,2035,2035,2037,2037,2037,2039,2039,2039,2039,2040,2040,2040,2040,2040,2040,2042,2043,2043,2045,2047,2049,2050,2050,2052,2054,2058,2062,2064,2065,2065,2065,2063,2063,2062,2058,2052,2046,2042,2041,2041,2041,2042,2042,2042,2041,2040,2040,2040,2040,2040,2039,2039,2039,2040,2041,2041,2041,2039,2037,2035,2039,2049,2071,2110,2165,2228,2277,2282,2244,2182,2114,2065,2043,2035,2036,2042,2046,2045,2043,2043,2043,2043,2043,2043,2044,2045,2046,2047,2048,2050,2052,2052,2053,2054,2054,2054,2056,2057,2059,2061,2063,2065,2067,2069,2071,2073,2077,2080,2084,2089,2094,2098,2104,2110,2116,2124,2130,2136,2142,2147,2151,2155,2159,2160,2157,2148,2137,2124,2109,2093,2076,2059,2044,2030,2019,2010,2002,1996,1992,1988,1986,1986,1985,1985,1985,1985,1985,1987,1988,1989,1991,1993,1994,1995,1996,1996,1996,1996,1996,1997,1998,1998,2000,2000,2000,2002,2003,2004,2005,2005,2005,2006,2007,2007,2009,2009,2009,2011,2013,2013,2015,2015,2015,2016,2018,2018,2020,2020,2022,2023,2024,2026,2026,2026,2026,2026,2026,2026,2026,2026,2026,2026,2026,2028,2028,2028,2028,2028,2028,2028,2028,2030,2031,2032,2034,2034,2033,2032,2032,2032,2033,2035,2035,2036,2038,2038,2038,2038,2039,2040,2040,2041,2042,2044,2046,2048,2049,2051,2055,2060,2064,2065,2064,2063,2063,2063,2061,2058,2052,2046,2041,2038,2038,2038,2038,2038,2036,2035,2035,2033,2032,2032,2032,2032,2034,2036,2038,2040,2040,2040,2040,2039,2037,2036,2041,2050,2068,2102,2148,2198,2238,2242,2208,2153,2093,2051,2032,2029,2034,2042,2047,2048,2048,2048,2048,2048,2048,2048,2048,2048,2049,2050,2051,2053,2053,2053,2053,2054,2056,2056,2058,2058,2060,2061,2062,2064,2066,2068,2072,2076,2080,2083,2086,2089,2093,2097,2103,2109,2114,2119,2126,2132,2138,2142,2146,2149,2150,2150,2147,2140,2130,2118,2104,2090,2074,2059,2046,2034,2023,2015,2007,2001,1998,1995,1993,1992,1992,1992,1992,1992,1992,1992,1992,1994,1994,1995,1996,1996,1997,1998,1998,1998,1998,1998,2000,2001,2001,2003,2003,2004,2006,2007,2008,2010,2010,2012,2014,2016,2018,2019,2020,2021,2021,2021,2021,2023,2023,2025,2025,2025,2025,2025,2025,2025,2027,2028,2029,2029,2029,2028,2028,2027,2028,2029,2029,2029,2029,2029,2029,2029,2029,2029,2031,2031,2033,2034,2035,2035,2035,2035,2036,2037,2037,2039,2039,2039,2039,2040,2041,2041,2041,2043,2043,2045,2047,2049,2050,2050,2051,2055,2059,2061,2063,2063,2061,2060,2060,2060,2059,2054,2049,2045,2042,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2041,2042,2044,2044,2046,2046,2044,2042,2040,2042,2050,2069,2105,2156,2214,2261,2269,2235,2177,2115,2069,2046,2038,2038,2043,2046,2046,2045,2044,2043,2041,2041,2041,2042,2044,2046,2047,2047,2048,2050,2052,2054,2054,2054,2056,2056,2056,2057,2058,2059,2061,2063,2065,2067,2070,2072,2075,2079,2082,2086,2091,2097,2103,2109,2116,2123,2129,2137,2137,2151,2137,2169,2122,2192,2070,2276},
{1491,2121,1919,2029,1960,2004,1975,1991,1981,1989,1991,1995,1998,2000,2002,2004,2006,2014,2031,2059,2097,2141,2185,2228,2269,2309,2352,2395,2429,2447,2449,2432,2397,2346,2283,2209,2134,2061,1996,1946,1914,1900,1894,1890,1887,1886,1886,1885,1883,1884,1887,1892,1897,1900,1900,1900,1900,1902,1904,1906,1906,1908,1909,1907,1905,1904,1902,1903,1905,1907,1911,1913,1917,1924,1933,1944,1957,1970,1985,2000,2014,2025,2031,2033,2032,2030,2028,2027,2027,2027,2025,2024,2021,2014,2008,2003,1999,1998,1998,1996,1996,1996,1996,1998,2002,2005,2008,2011,2013,2015,2015,2015,2013,2013,2015,2017,2017,2017,2016,2014,2012,2012,2015,2019,2023,2025,2027,2029,2031,2032,2032,2032,2032,2032,2034,2035,2036,2037,2037,2037,2037,2037,2041,2055,2076,2108,2155,2207,2248,2253,2205,2129,2057,2011,2001,2010,2021,2033,2042,2047,2049,2051,2052,2052,2054,2056,2056,2058,2060,2062,2064,2064,2066,2068,2070,2072,2074,2077,2081,2086,2092,2099,2107,2113,2119,2126,2134,2142,2150,2158,2164,2170,2175,2177,2179,2179,2177,2172,2163,2149,2131,2109,2087,2066,2049,2034,2023,2015,2009,2005,2001,1995,1992,1992,1994,1996,1998,1998,1997,1998,2000,2004,2006,2007,2005,2003,2002,2002,2004,2006,2008,2008,2007,2007,2008,2009,2010,2011,2012,2016,2019,2021,2020,2018,2016,2014,2014,2014,2015,2017,2019,2021,2021,2021,2021,2023,2025,2027,2027,2027,2026,2026,2026,2027,2031,2035,2037,2039,2041,2043,2045,2047,2049,2051,2053,2054,2054,2053,2048,2042,2036,2030,2025,2024,2024,2024,2026,2027,2027,2025,2025,2025,2026,2029,2031,2033,2033,2033,2031,2029,2031,2043,2062,2099,2152,2208,2250,2246,2193,2119,2048,2007,1997,2000,2009,2023,2033,2039,2042,2041,2041,2044,2046,2047,2048,2050,2052,2054,2055,2057,2061,2063,2066,2069,2072,2076,2080,2083,2087,2091,2097,2104,2110,2117,2125,2133,2141,2149,2157,2163,2170,2176,2179,2181,2179,2174,2165,2152,2135,2115,2095,2075,2057,2042,2029,2018,2011,2005,2001,1997,1993,1990,1989,1990,1991,1991,1990,1990,1991,1993,1995,1995,1997,1997,1997,1997,1998,1999,2000,2002,2004,2005,2004,2003,2003,2003,2006,2008,2012,2014,2016,2017,2015,2013,2012,2014,2016,2017,2017,2017,2018,2019,2019,2019,2019,2021,2021,2021,2021,2021,2021,2023,2025,2025,2025,2025,2025,2025,2025,2025,2025,2025,2025,2024,2025,2029,2031,2032,2032,2032,2034,2036,2038,2037,2035,2034,2034,2036,2037,2037,2037,2037,2038,2042,2045,2047,2049,2051,2054,2058,2060,2061,2061,2061,2061,2062,2062,2057,2050,2042,2035,2031,2030,2032,2034,2034,2034,2036,2036,2038,2039,2039,2039,2038,2038,2036,2034,2034,2042,2058,2086,2131,2184,2234,2250,2212,2142,2067,2013,1994,1996,2005,2020,2034,2043,2046,2046,2046,2046,2046,2047,2049,2053,2057,2061,2063,2065,2066,2066,2066,2068,2070,2074,2080,2084,2088,2092,2096,2102,2106,2112,2120,2130,2139,2147,2157,2165,2175,2182,2187,2188,2186,2184,2179,2170,2157,2140,2119,2096,2074,2055,2038,2025,2014,2006,1999,1993,1987,1984,1982,1982,1984,1987,1988,1988,1988,1988,1990,1990,1990,1988,1987,1988,1990,1993,1995,1997,2001,2008,2024,2048,2083,2126,2172,2219,2266,2312,2359,2409,2453,2478,2484,2475,2448,2404,2346,2273,2190,2105,2025,1958,1914,1893,1885,1880,1876,1874,1874,1874,1874,1874,1874,1874,1877,1881,1887,1891,1893,1894,1892,1892,1893,1896,1898,1900,1900,1900,1898,1898,1897,1897,1899,1903,1908,1916,1924,1934,1947,1962,1978,1992,2005,2015,2022,2027,2030,2030,2030,2028,2026,2024,2022,2020,2021,2023,2024,2023,2019,2013,2008,2004,2002,2002,2003,2005,2007,2008,2008,2008,2008,2009,2011,2013,2015,2016,2016,2014,2014,2012,2012,2014,2017,2021,2024,2027,2029,2029,2029,2028,2027,2027,2026,2026,2028,2030,2033,2035,2037,2037,2039,2039,2041,2040,2038,2039,2047,2063,2091,2135,2185,2228,2244,2209,2136,2057,2001,1985,2000,2022,2039,2048,2051,2053,2055,2055,2056,2057,2059,2063,2066,2067,2067,2067,2067,2069,2073,2076,2080,2084,2087,2091,2093,2096,2099,2104,2111,2119,2127,2135,2143,2151,2159,2165,2171,2175,2178,2181,2183,2182,2177,2167,2152,2134,2115,2093,2074,2056,2042,2028,2016,2006,1999,1997,1997,1996,1994,1994,1994,1995,1996,1996,1996,1996,1996,1996,1998,2000,2004,2006,2008,2010,2009,2009,2009,2011,2011,2010,2008,2008,2008,2010,2013,2016,2018,2019,2020,2022,2022,2021,2019,2019,2018,2018,2018,2018,2018,2018,2018,2018,2018,2019,2021,2025,2028,2030,2030,2031,2033,2036,2039,2040,2041,2043,2045,2047,2049,2049,2049,2049,2049,2051,2050,2046,2039,2032,2027,2026,2026,2025,2025,2026,2027,2027,2027,2027,2027,2027,2029,2030,2032,2034,2035,2034,2033,2041,2055,2081,2124,2175,2221,2232,2192,2121,2049,1999,1985,1992,2003,2018,2031,2040,2045,2046,2046,2046,2046,2047,2049,2052,2058,2061,2063,2063,2063,2065,2067,2071,2074,2078,2082,2085,2087,2089,2093,2100,2109,2119,2129,2136,2142,2148,2154,2162,2170,2178,2183,2185,2184,2179,2171,2159,2142,2121,2099,2078,2060,2046,2035,2025,2016,2008,2001,1997,1993,1990,1988,1988,1989,1990,1991,1993,1995,1997,1998,1997,1995,1995,1995,1996,2000,2003,2005,2006,2005,2005,2004,2004,2004,2005,2006,2007,2009,2009,2009,2011,2013,2014,2014,2014,2015,2018,2020,2022,2022,2021,2020,2020,2020,2021,2023,2023,2023,2023,2022,2021,2020,2021,2023,2025,2027,2028,2028,2027,2027,2028,2030,2032,2034,2034,2033,2032,2032,2032,2034,2034,2034,2034,2034,2034,2035,2036,2037,2039,2041,2042,2043,2045,2047,2049,2052,2056,2059,2062,2063,2063,2063,2064,2064,2061,2054,2046,2038,2033,2032,2034,2035,2035,2034,2034,2034,2033,2033,2033,2033,2035,2037,2039,2040,2040,2043,2051,2067,2095,2138,2187,2228,2233,2189,2121,2054,2010,1997,2001,2010,2022,2033,2040,2044,2046,2048,2050,2050,2051,2053,2055,2058,2060,2060,2062,2064,2065,2066,2069,2073,2077,2080,2082,2087,2093,2100,2106,2112,2118,2124,2132,2141,2150,2158,2166,2174,2180,2186,2188,2187,2182,2175,2165,2151,2133,2113,2092,2071,2052,2034,2020,2009,2002,1997,1993,1990,1989,1988,1988,1986,1985,1984,1983,1983,1984,1987,1989,1991,1992,1992,1993,1995,1996,1996,1997,1999,2003,2013,2033,2061,2100,2145,2193,2241,2288,2333,2379,2424,2458,2475,2480,2471,2446,2404,2343,2263,2172,2081,2000,1938,1900,1884,1877,1872,1870,1870,1870,1869,1870,1873,1876,1878,1880,1880,1882,1883,1884,1886,1888,1890,1892,1893,1893,1893,1892,1892,1892,1892,1894,1895,1897,1901,1906,1913,1921,1932,1945,1961,1977,1993,2007,2018,2027,2033,2034,2032,2030,2028,2028,2026,2023,2020,2019,2022,2026,2027,2025,2020,2014,2009,2006,2004,2003,2003,2003,2005,2006,2007,2009,2010,2011,2011,2012,2013,2014,2016,2018,2019,2020,2021,2021,2021,2021,2023,2025,2027,2029,2030,2030,2030,2030,2030,2030,2032,2033,2035,2037,2037,2037,2037,2037,2037,2039,2042,2055,2078,2114,2166,2220,2261,2262,2210,2128,2051,2005,1997,2009,2025,2040,2048,2051,2052,2052,2053,2055,2057,2059,2060,2060,2062,2064,2066,2068,2071,2073,2075,2075,2078,2083,2089,2093,2099,2105,2111,2117,2123,2130,2138,2146,2154,2162,2170,2178,2184,2187,2188,2187,2183,2176,2166,2151,2130,2108,2086,2065,2049,2036,2024,2014,2007,2001,1997,1994,1993,1993,1993,1992,1992,1994,1996,1998,1999,1998,1998,1998,1999,2001,2002,2001,2001,2002,2004,2006,2007,2007,2007,2007,2007,2009,2009,2011,2013,2016,2018,2018,2018,2016,2016,2016,2016,2015,2015,2016,2018,2019,2019,2019,2017,2015,2014,2015,2019,2024,2030,2033,2032,2030,2028,2027,2028,2030,2032,2036,2038,2040,2042,2044,2045,2045,2046,2048,2053,2058,2061,2062,2058,2051,2043,2035,2030,2028,2027,2026,2026,2026,2028,2028,2030,2031,2031,2033,2033,2033,2033,2033,2033,2031,2032,2039,2052,2077,2119,2170,2219,2237,2202,2131,2055,2000,1983,1993,2010,2027,2038,2043,2044,2045,2047,2047,2050,2053,2055,2056,2056,2057,2059,2062,2065,2067,2067,2069,2071,2075,2081,2087,2092,2096,2100,2104,2109,2115,2123,2131,2139,2147,2155,2163,2170,2176,2179,2179,2176,2170,2162,2151,2138,2121,2102,2082,2062,2045,2031,2020,2010,2003,1999,1995,1992,1990,1990,1990,1992,1993,1995,1997,1999,1999,1998,1997,1997,1997,1999,2000,2001,2003,2005,2007,2008,2008,2008,2008,2008,2010,2012,2015,2017,2017,2015,2014,2014,2015,2017,2018,2018,2018,2018,2018,2017,2017,2017,2017,2018,2019,2020,2021,2021,2021,2023,2023,2024,2026,2027,2027,2026,2025,2025,2025,2026,2027,2027,2029,2031,2033,2033,2032,2030,2030,2032,2034,2036,2035,2033,2033,2033,2033,2035,2037,2038,2038,2040,2041,2041,2044,2046,2049,2052,2054,2057,2059,2059,2059,2059,2060,2063,2065,2064,2060,2053,2045,2037,2032,2031,2032,2034,2036,2037,2037,2037,2037,2037,2036,2035,2035,2035,2035,2036,2040,2051,2069,2101,2147,2198,2239,2237,2187,2112,2041,2000,1993,2001,2014,2027,2036,2041,2043,2045,2047,2048,2048,2049,2053,2056,2059,2061,2061,2061,2064,2068,2071,2073,2075,2077,2080,2084,2090,2094,2098,2104,2109,2114,2121,2130,2141,2152,2162,2171,2177,2182,2185,2186,2185,2181,2176,2165,2148,2129,2106,2083,2063,2046,2031,2020,2012,2004,1998,1993,1989,1986,1984,1983,1983,1983,1983,1985,1985,1987,1987,1987,1988,1990,1990,1992,1994,1994,1996,2000,2005,2018,2043,2079,2124,2173,2223,2271,2316,2363,2413,2456,2484,2494,2488,2466,2429,2379,2308,2222,2128,2036,1959,1907,1883,1875,1873,1872,1871,1869,1869,1867,1867,1867,1869,1871,1874,1876,1878,1880,1882,1884,1884,1885,1886,1887,1889,1891,1893,1893,1893,1892,1892,1894,1897,1901,1908,1917,1929,1941,1951,1963,1976,1992,2006,2019,2026,2031,2032,2029,2025,2022,2021,2023,2025,2025,2023,2021,2021,2023,2025,2024,2018,2012,2006,2003,2003,2003,2003,2003,2003,2004,2006,2008,2010,2011,2011,2012,2014,2015,2017,2018,2018,2017,2017,2018,2020,2022,2023,2022,2020,2021,2023,2027,2031,2032,2033,2034,2034,2034,2034,2035,2036,2039,2041,2041,2041,2045,2057,2079,2118,2172,2227,2267,2260,2202,2120,2046,2007,2003,2014,2028,2041,2049,2053,2054,2054,2054,2056,2056,2056,2057,2058,2059,2062,2064,2066,2068,2071,2075,2079,2082,2084,2088,2092,2097,2103,2111,2118,2124,2129,2136,2144,2154,2163,2169,2175,2181,2186,2189,2188,2183,2174,2163,2148,2130,2109,2086,2065,2048,2035,2024,2014,2005,2000,1997,1995,1994,1994,1994,1996,1997,1997,1997,1997,1998,2000,2000,2002,2002,2002,2001,2001,2003,2003,2006,2008,2011,2013,2012,2011,2011,2013,2015,2016,2016,2015,2013,2013,2013,2013,2015,2016,2017,2018,2018,2020,2020,2020,2020,2019,2019,2020,2022,2023,2023,2025,2025,2025,2025,2024,2024,2024,2025,2029,2032,2036,2039,2042,2044,2044,2046,2047,2048,2050,2050,2052,2054,2056,2057,2054,2049,2041,2032,2027,2025,2026,2028,2030,2031,2031,2033,2027,2036,2020,2050,2005,2075,1963,2170}
};