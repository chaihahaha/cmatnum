#include "fAx2862.h"

inline int fAx2862(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2862.data[i][j] = -bmats.A_18_14.data[i][j] - bmats.A_18_15.data[i][j] - bmats.A_18_16.data[i][j] - bmats.A_18_17.data[i][j] - bmats.A_18_18.data[i][j] - bmats.A_18_19.data[i][j] - bmats.A_18_20.data[i][j] - bmats.A_18_22.data[i][j];
        }
    }
    return 0;
}
