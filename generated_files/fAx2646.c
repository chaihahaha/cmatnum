#include "fAx2646.h"

inline int fAx2646(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2646.data[i][j] = -bmats.A_21_12.data[i][j] - bmats.A_21_13.data[i][j] - bmats.A_21_16.data[i][j] - bmats.A_21_17.data[i][j] - bmats.A_21_18.data[i][j] - bmats.A_21_19.data[i][j] - bmats.A_21_20.data[i][j];
        }
    }
    return 0;
}
