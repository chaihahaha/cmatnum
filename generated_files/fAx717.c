#include "fAx717.h"

inline int fAx717(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax717.data[i][j] = bmats.A_17_12.data[i][j] + bmats.A_17_15.data[i][j] + bmats.A_17_16.data[i][j] + bmats.A_17_17.data[i][j] + bmats.A_17_18.data[i][j] + bmats.A_17_19.data[i][j] + bmats.A_17_20.data[i][j] + bmats.A_17_21.data[i][j] + bmats.A_17_22.data[i][j];
        }
    }
    return 0;
}
