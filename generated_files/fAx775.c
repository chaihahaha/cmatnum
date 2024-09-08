#include "fAx775.h"

inline int fAx775(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax775.data[i][j] = bmats.A_3_17.data[i][j] + bmats.A_3_18.data[i][j] + bmats.A_3_19.data[i][j] + bmats.A_3_20.data[i][j] + bmats.A_3_21.data[i][j] + bmats.A_3_22.data[i][j] + bmats.A_3_23.data[i][j] + bmats.A_3_24.data[i][j] + bmats.A_3_25.data[i][j] + bmats.A_3_26.data[i][j] + bmats.A_3_27.data[i][j] + bmats.A_3_28.data[i][j] + bmats.A_3_29.data[i][j] + bmats.A_3_30.data[i][j];
        }
    }
    return 0;
}
