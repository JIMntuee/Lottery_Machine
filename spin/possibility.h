//      轉盤編號  機率   獎品編號
#define one      0     // 1
#define two      0     // 15
#define three    0    // 3
#define four     0    // 13
#define five     0     // 5
#define six      0     // 11
#define seven    0     // 7
#define eight    50    // 9
#define nine     0     // 16
#define ten      0     // 2
#define eleven   0     // 14
#define twelve   0     // 4
#define thirteen 29    // 12
#define forteen  371   // 6
#define fifteen  50    // 10
#define sixteen  0     // 8
#define BASE_NUMBER 500

int prize[16] = { one, two, three, four, five, six, seven, eight, 
                nine, ten, eleven, twelve, thirteen, forteen, fifteen, sixteen };

int getprize(int r) { // return the index of LED
    for(int i = 0; i < 16; i++){
        r -= prize[i];
        if(r < 0)   return i+1;
    }
}
