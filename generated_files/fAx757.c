#include "fAx757.h"

inline int fAx757(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax757.data[i][j] = bmats.A_12_17.data[i][j] + bmats.A_12_18.data[i][j] + bmats.A_12_19.data[i][j] + bmats.A_12_20.data[i][j] + bmats.A_12_21.data[i][j] + bmats.A_12_22.data[i][j] + bmats.A_12_23.data[i][j] + bmats.A_12_24.data[i][j] + bmats.A_12_25.data[i][j] + bmats.A_12_26.data[i][j] + bmats.A_12_27.data[i][j] + bmats.A_12_28.data[i][j] + bmats.A_12_29.data[i][j] + bmats.A_12_30.data[i][j];
        }
    }
    return 0;
}