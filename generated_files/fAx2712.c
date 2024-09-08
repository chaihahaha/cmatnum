#include "fAx2712.h"

inline int fAx2712(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2712.data[i][j] = -bmats.A_20_14.data[i][j] - bmats.A_20_15.data[i][j] - bmats.A_20_16.data[i][j] - bmats.A_20_18.data[i][j] - bmats.A_20_19.data[i][j] - bmats.A_20_21.data[i][j] - bmats.A_20_22.data[i][j];
        }
    }
    return 0;
}
