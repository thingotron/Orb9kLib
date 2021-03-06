#include <avr/pgmspace.h>

const unsigned short sensitivity_1_chart[] =
  {
    0,
    1,
    2,
    4,
    5,
    7,
    8,
    10,
    11,
    13,
    14,
    16,
    17,
    19,
    20,
    22,
    23,
    25,
    26,
    28,
    29,
    31,
    32,
    34,
    35,
    37,
    38,
    39,
    41,
    42,
    44,
    45,
    47,
    48,
    50,
    51,
    53,
    54,
    55,
    57,
    58,
    60,
    61,
    63,
    64,
    65,
    67,
    68,
    70,
    71,
    73,
    74,
    75,
    77,
    78,
    80,
    81,
    83,
    84,
    85,
    87,
    88,
    90,
    91,
    92,
    94,
    95,
    97,
    98,
    99,
    101,
    102,
    104,
    105,
    106,
    108,
    109,
    111,
    112,
    113,
    115,
    116,
    117,
    119,
    120,
    122,
    123,
    124,
    126,
    127,
    128,
    130,
    131,
    132,
    134,
    135,
    137,
    138,
    139,
    141,
    142,
    143,
    145,
    146,
    147,
    149,
    150,
    151,
    153,
    154,
    155,
    157,
    158,
    159,
    161,
    162,
    163,
    165,
    166,
    167,
    169,
    170,
    171,
    172,
    174,
    175,
    176,
    178,
    179,
    180,
    182,
    183,
    184,
    185,
    187,
    188,
    189,
    191,
    192,
    193,
    194,
    196,
    197,
    198,
    200,
    201,
    202,
    203,
    205,
    206,
    207,
    208,
    210,
    211,
    212,
    213,
    215,
    216,
    217,
    218,
    220,
    221,
    222,
    223,
    225,
    226,
    227,
    228,
    230,
    231,
    232,
    233,
    234,
    236,
    237,
    238,
    239,
    241,
    242,
    243,
    244,
    245,
    247,
    248,
    249,
    250,
    251,
    253,
    254,
    255,
    256,
    257,
    259,
    260,
    261,
    262,
    263,
    264,
    266,
    267,
    268,
    269,
    270,
    271,
    273,
    274,
    275,
    276,
    277,
    278,
    280,
    281,
    282,
    283,
    284,
    285,
    286,
    288,
    289,
    290,
    291,
    292,
    293,
    294,
    296,
    297,
    298,
    299,
    300,
    301,
    302,
    303,
    304,
    306,
    307,
    308,
    309,
    310,
    311,
    312,
    313,
    314,
    315,
    317,
    318,
    319,
    320,
    321,
    322,
    323,
    324,
    325,
    326,
    327,
    328,
    329,
    330,
    332,
    333,
    334,
    335,
    336,
    337,
    338,
    339,
    340,
    341,
    342,
    343,
    344,
    345,
    346,
    347,
    348,
    349,
    350,
    351,
    352,
    353,
    354,
    355,
    356,
    357,
    358,
    359,
    360,
    361,
    362,
    363,
    364,
    365,
    366,
    367,
    368,
    369,
    370,
    371,
    372,
    373,
    374,
    375,
    376,
    377,
    378,
    379,
    380,
    381,
    382,
    383,
    384,
    385,
    386,
    387,
    387,
    388,
    389,
    390,
    391,
    392,
    393,
    394,
    395,
    396,
    397,
    398,
    398,
    399,
    400,
    401,
    402,
    403,
    404,
    405,
    406,
    407,
    407,
    408,
    409,
    410,
    411,
    412,
    413,
    414,
    414,
    415,
    416,
    417,
    418,
    419,
    420,
    420,
    421,
    422,
    423,
    424,
    425,
    425,
    426,
    427,
    428,
    429,
    429,
    430,
    431,
    432,
    433,
    434,
    434,
    435,
    436,
    437,
    438,
    438,
    439,
    440,
    441,
    441,
    442,
    443,
    444,
    444,
    445,
    446,
    447,
    448,
    448,
    449,
    450,
    450,
    451,
    452,
    453,
    453,
    454,
    455,
    456,
    456,
    457,
    458,
    458,
    459,
    460,
    461,
    461,
    462,
    463,
    463,
    464,
    465,
    465,
    466,
    467,
    467,
    468,
    469,
    469,
    470,
    471,
    471,
    472,
    473,
    473,
    474,
    474,
    475,
    476,
    476,
    477,
    477,
    478,
    479,
    479,
    480,
    480,
    481,
    482,
    482,
    483,
    483,
    484,
    485,
    485,
    486,
    486,
    487,
    487,
    488,
    488,
    489,
    489,
    490,
    490,
    491,
    491,
    492,
    492,
    493,
    493,
    494,
    494,
    495,
    495,
    496,
    496,
    497,
    497,
    498,
    498,
    499,
    499,
    499,
    500,
    500,
    501,
    501,
    502,
    502,
    502,
    503,
    503,
    504,
    504,
    504,
    505,
    505,
    505,
    506,
    506,
    506,
    507,
    507,
    507,
    508,
    508,
    508,
    508,
    509,
    509,
    509,
    509,
    510,
    510,
    510,
    510,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    513,
    513,
    513,
    513,
    513,
    514,
    514,
    514,
    514,
    515,
    515,
    515,
    515,
    516,
    516,
    516,
    517,
    517,
    517,
    518,
    518,
    518,
    519,
    519,
    520,
    520,
    520,
    521,
    521,
    521,
    522,
    522,
    523,
    523,
    524,
    524,
    524,
    525,
    525,
    526,
    526,
    527,
    527,
    528,
    528,
    529,
    529,
    530,
    530,
    531,
    531,
    532,
    532,
    533,
    533,
    534,
    534,
    535,
    535,
    536,
    536,
    537,
    537,
    538,
    539,
    539,
    540,
    540,
    541,
    541,
    542,
    543,
    543,
    544,
    544,
    545,
    546,
    546,
    547,
    547,
    548,
    549,
    549,
    550,
    550,
    551,
    552,
    552,
    553,
    554,
    554,
    555,
    556,
    556,
    557,
    558,
    558,
    559,
    560,
    560,
    561,
    562,
    562,
    563,
    564,
    565,
    565,
    566,
    567,
    567,
    568,
    569,
    570,
    570,
    571,
    572,
    573,
    573,
    574,
    575,
    576,
    576,
    577,
    578,
    579,
    579,
    580,
    581,
    582,
    582,
    583,
    584,
    585,
    585,
    586,
    587,
    588,
    589,
    589,
    590,
    591,
    592,
    593,
    594,
    594,
    595,
    596,
    597,
    598,
    598,
    599,
    600,
    601,
    602,
    603,
    603,
    604,
    605,
    606,
    607,
    608,
    609,
    609,
    610,
    611,
    612,
    613,
    614,
    615,
    616,
    616,
    617,
    618,
    619,
    620,
    621,
    622,
    623,
    624,
    625,
    625,
    626,
    627,
    628,
    629,
    630,
    631,
    632,
    633,
    634,
    635,
    636,
    637,
    637,
    638,
    639,
    640,
    641,
    642,
    643,
    644,
    645,
    646,
    647,
    648,
    649,
    650,
    651,
    652,
    653,
    654,
    655,
    656,
    657,
    658,
    659,
    660,
    661,
    662,
    663,
    664,
    665,
    666,
    667,
    668,
    669,
    670,
    671,
    672,
    673,
    674,
    675,
    676,
    677,
    678,
    679,
    680,
    681,
    682,
    683,
    684,
    685,
    686,
    687,
    688,
    689,
    690,
    691,
    693,
    694,
    695,
    696,
    697,
    698,
    699,
    700,
    701,
    702,
    703,
    704,
    705,
    706,
    708,
    709,
    710,
    711,
    712,
    713,
    714,
    715,
    716,
    717,
    719,
    720,
    721,
    722,
    723,
    724,
    725,
    726,
    728,
    729,
    730,
    731,
    732,
    733,
    734,
    735,
    737,
    738,
    739,
    740,
    741,
    742,
    743,
    745,
    746,
    747,
    748,
    749,
    750,
    752,
    753,
    754,
    755,
    756,
    757,
    759,
    760,
    761,
    762,
    763,
    764,
    766,
    767,
    768,
    769,
    770,
    772,
    773,
    774,
    775,
    776,
    778,
    779,
    780,
    781,
    782,
    784,
    785,
    786,
    787,
    789,
    790,
    791,
    792,
    793,
    795,
    796,
    797,
    798,
    800,
    801,
    802,
    803,
    805,
    806,
    807,
    808,
    810,
    811,
    812,
    813,
    815,
    816,
    817,
    818,
    820,
    821,
    822,
    823,
    825,
    826,
    827,
    829,
    830,
    831,
    832,
    834,
    835,
    836,
    838,
    839,
    840,
    841,
    843,
    844,
    845,
    847,
    848,
    849,
    851,
    852,
    853,
    855,
    856,
    857,
    858,
    860,
    861,
    862,
    864,
    865,
    866,
    868,
    869,
    870,
    872,
    873,
    874,
    876,
    877,
    878,
    880,
    881,
    882,
    884,
    885,
    886,
    888,
    889,
    891,
    892,
    893,
    895,
    896,
    897,
    899,
    900,
    901,
    903,
    904,
    906,
    907,
    908,
    910,
    911,
    912,
    914,
    915,
    917,
    918,
    919,
    921,
    922,
    924,
    925,
    926,
    928,
    929,
    931,
    932,
    933,
    935,
    936,
    938,
    939,
    940,
    942,
    943,
    945,
    946,
    948,
    949,
    950,
    952,
    953,
    955,
    956,
    958,
    959,
    960,
    962,
    963,
    965,
    966,
    968,
    969,
    970,
    972,
    973,
    975,
    976,
    978,
    979,
    981,
    982,
    984,
    985,
    986,
    988,
    989,
    991,
    992,
    994,
    995,
    997,
    998,
    1000,
    1001,
    1003,
    1004,
    1006,
    1007,
    1009,
    1010,
    1012,
    1013,
    1015,
    1016,
    1018,
    1019,
    1021,
    1022,
  };
