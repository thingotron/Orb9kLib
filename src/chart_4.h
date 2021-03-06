#include <avr/pgmspace.h>

const unsigned short sensitivity_4_chart[] =
  {
    0,
    2,
    5,
    8,
    11,
    14,
    17,
    20,
    23,
    26,
    29,
    32,
    35,
    38,
    40,
    43,
    46,
    49,
    52,
    54,
    57,
    60,
    63,
    65,
    68,
    71,
    74,
    76,
    79,
    82,
    84,
    87,
    90,
    92,
    95,
    97,
    100,
    103,
    105,
    108,
    110,
    113,
    115,
    118,
    120,
    123,
    125,
    128,
    130,
    133,
    135,
    138,
    140,
    143,
    145,
    147,
    150,
    152,
    155,
    157,
    159,
    162,
    164,
    166,
    169,
    171,
    173,
    175,
    178,
    180,
    182,
    184,
    187,
    189,
    191,
    193,
    195,
    198,
    200,
    202,
    204,
    206,
    208,
    210,
    212,
    215,
    217,
    219,
    221,
    223,
    225,
    227,
    229,
    231,
    233,
    235,
    237,
    239,
    241,
    243,
    245,
    247,
    249,
    251,
    252,
    254,
    256,
    258,
    260,
    262,
    264,
    266,
    267,
    269,
    271,
    273,
    275,
    276,
    278,
    280,
    282,
    283,
    285,
    287,
    289,
    290,
    292,
    294,
    296,
    297,
    299,
    301,
    302,
    304,
    305,
    307,
    309,
    310,
    312,
    314,
    315,
    317,
    318,
    320,
    321,
    323,
    324,
    326,
    328,
    329,
    331,
    332,
    334,
    335,
    336,
    338,
    339,
    341,
    342,
    344,
    345,
    347,
    348,
    349,
    351,
    352,
    353,
    355,
    356,
    358,
    359,
    360,
    362,
    363,
    364,
    366,
    367,
    368,
    369,
    371,
    372,
    373,
    374,
    376,
    377,
    378,
    379,
    381,
    382,
    383,
    384,
    385,
    387,
    388,
    389,
    390,
    391,
    392,
    393,
    395,
    396,
    397,
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
    409,
    410,
    411,
    412,
    413,
    414,
    415,
    416,
    417,
    417,
    418,
    419,
    420,
    421,
    422,
    423,
    424,
    425,
    426,
    427,
    428,
    429,
    430,
    430,
    431,
    432,
    433,
    434,
    435,
    436,
    436,
    437,
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
    455,
    456,
    457,
    457,
    458,
    459,
    459,
    460,
    461,
    461,
    462,
    463,
    463,
    464,
    464,
    465,
    466,
    466,
    467,
    467,
    468,
    469,
    469,
    470,
    470,
    471,
    471,
    472,
    473,
    473,
    474,
    474,
    475,
    475,
    476,
    476,
    477,
    477,
    478,
    478,
    479,
    479,
    480,
    480,
    481,
    481,
    481,
    482,
    482,
    483,
    483,
    484,
    484,
    485,
    485,
    485,
    486,
    486,
    487,
    487,
    487,
    488,
    488,
    489,
    489,
    489,
    490,
    490,
    490,
    491,
    491,
    491,
    492,
    492,
    492,
    493,
    493,
    493,
    494,
    494,
    494,
    495,
    495,
    495,
    496,
    496,
    496,
    496,
    497,
    497,
    497,
    498,
    498,
    498,
    498,
    499,
    499,
    499,
    499,
    500,
    500,
    500,
    500,
    501,
    501,
    501,
    501,
    501,
    502,
    502,
    502,
    502,
    503,
    503,
    503,
    503,
    503,
    504,
    504,
    504,
    504,
    504,
    504,
    505,
    505,
    505,
    505,
    505,
    505,
    506,
    506,
    506,
    506,
    506,
    506,
    506,
    507,
    507,
    507,
    507,
    507,
    507,
    507,
    507,
    508,
    508,
    508,
    508,
    508,
    508,
    508,
    508,
    508,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    509,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
    510,
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
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
    511,
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
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
    512,
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
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    513,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    514,
    515,
    515,
    515,
    515,
    515,
    515,
    515,
    515,
    515,
    516,
    516,
    516,
    516,
    516,
    516,
    516,
    516,
    517,
    517,
    517,
    517,
    517,
    517,
    517,
    518,
    518,
    518,
    518,
    518,
    518,
    519,
    519,
    519,
    519,
    519,
    520,
    520,
    520,
    520,
    520,
    520,
    521,
    521,
    521,
    521,
    522,
    522,
    522,
    522,
    522,
    523,
    523,
    523,
    523,
    524,
    524,
    524,
    524,
    525,
    525,
    525,
    525,
    526,
    526,
    526,
    527,
    527,
    527,
    527,
    528,
    528,
    528,
    529,
    529,
    529,
    530,
    530,
    530,
    531,
    531,
    531,
    532,
    532,
    532,
    533,
    533,
    533,
    534,
    534,
    534,
    535,
    535,
    536,
    536,
    536,
    537,
    537,
    538,
    538,
    539,
    539,
    539,
    540,
    540,
    541,
    541,
    542,
    542,
    542,
    543,
    543,
    544,
    544,
    545,
    545,
    546,
    546,
    547,
    547,
    548,
    548,
    549,
    549,
    550,
    550,
    551,
    552,
    552,
    553,
    553,
    554,
    554,
    555,
    556,
    556,
    557,
    557,
    558,
    559,
    559,
    560,
    560,
    561,
    562,
    562,
    563,
    564,
    564,
    565,
    566,
    566,
    567,
    568,
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
    586,
    587,
    587,
    588,
    589,
    590,
    591,
    592,
    593,
    593,
    594,
    595,
    596,
    597,
    598,
    599,
    600,
    601,
    602,
    603,
    604,
    605,
    606,
    606,
    607,
    608,
    609,
    610,
    611,
    612,
    613,
    614,
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
    626,
    627,
    628,
    630,
    631,
    632,
    633,
    634,
    635,
    637,
    638,
    639,
    640,
    641,
    642,
    644,
    645,
    646,
    647,
    649,
    650,
    651,
    652,
    654,
    655,
    656,
    657,
    659,
    660,
    661,
    663,
    664,
    665,
    667,
    668,
    670,
    671,
    672,
    674,
    675,
    676,
    678,
    679,
    681,
    682,
    684,
    685,
    687,
    688,
    689,
    691,
    692,
    694,
    695,
    697,
    699,
    700,
    702,
    703,
    705,
    706,
    708,
    709,
    711,
    713,
    714,
    716,
    718,
    719,
    721,
    722,
    724,
    726,
    728,
    729,
    731,
    733,
    734,
    736,
    738,
    740,
    741,
    743,
    745,
    747,
    748,
    750,
    752,
    754,
    756,
    757,
    759,
    761,
    763,
    765,
    767,
    769,
    771,
    772,
    774,
    776,
    778,
    780,
    782,
    784,
    786,
    788,
    790,
    792,
    794,
    796,
    798,
    800,
    802,
    804,
    806,
    808,
    811,
    813,
    815,
    817,
    819,
    821,
    823,
    825,
    828,
    830,
    832,
    834,
    836,
    839,
    841,
    843,
    845,
    848,
    850,
    852,
    855,
    857,
    859,
    861,
    864,
    866,
    868,
    871,
    873,
    876,
    878,
    880,
    883,
    885,
    888,
    890,
    893,
    895,
    898,
    900,
    903,
    905,
    908,
    910,
    913,
    915,
    918,
    920,
    923,
    926,
    928,
    931,
    933,
    936,
    939,
    941,
    944,
    947,
    949,
    952,
    955,
    958,
    960,
    963,
    966,
    969,
    971,
    974,
    977,
    980,
    983,
    985,
    988,
    991,
    994,
    997,
    1000,
    1003,
    1006,
    1009,
    1012,
    1015,
    1018,
    1021,
  };
