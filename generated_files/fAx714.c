#include "fAx714.h"

inline int fAx714(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax714.data[i][j] = bmats.A_6_12.data[i][j] + bmats.A_6_15.data[i][j] + bmats.A_6_16.data[i][j] + bmats.A_6_17.data[i][j] + bmats.A_6_18.data[i][j] + bmats.A_6_19.data[i][j] + bmats.A_6_20.data[i][j] + bmats.A_6_21.data[i][j] + bmats.A_6_22.data[i][j];
        }
    }
    return 0;
}
