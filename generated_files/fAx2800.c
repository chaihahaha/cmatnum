#include "fAx2800.h"

inline int fAx2800(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2800.data[i][j] = -bmats.A_19_13.data[i][j] - bmats.A_19_14.data[i][j] - bmats.A_19_15.data[i][j] - bmats.A_19_16.data[i][j] - bmats.A_19_17.data[i][j] - bmats.A_19_18.data[i][j] - bmats.A_19_21.data[i][j];
        }
    }
    return 0;
}
