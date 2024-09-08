#include "fAx100.h"

inline int fAx100(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax100.data[i][j] = bmats.A_24_19.data[i][j] + bmats.A_24_20.data[i][j] + bmats.A_24_21.data[i][j] + bmats.A_24_22.data[i][j] + bmats.A_24_23.data[i][j] + bmats.A_24_24.data[i][j] + bmats.A_24_25.data[i][j] + bmats.A_24_26.data[i][j] + bmats.A_24_27.data[i][j] + bmats.A_24_28.data[i][j] + bmats.A_24_29.data[i][j] + bmats.A_24_30.data[i][j] + bmats.A_24_31.data[i][j] + bmats.A_24_32.data[i][j];
        }
    }
    return 0;
}
