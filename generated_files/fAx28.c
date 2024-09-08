#include "fAx28.h"

inline int fAx28(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax28.data[i][j] = bmats.A_19_17.data[i][j] + bmats.A_19_18.data[i][j] + bmats.A_19_19.data[i][j] + bmats.A_19_20.data[i][j] + bmats.A_19_21.data[i][j] + bmats.A_19_22.data[i][j] + bmats.A_19_23.data[i][j] + bmats.A_19_24.data[i][j] + bmats.A_19_25.data[i][j] + bmats.A_19_26.data[i][j] + bmats.A_19_29.data[i][j] + bmats.A_19_30.data[i][j] + bmats.A_19_31.data[i][j] + bmats.A_19_32.data[i][j];
        }
    }
    return 0;
}
