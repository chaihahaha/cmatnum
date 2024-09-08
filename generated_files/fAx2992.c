#include "fAx2992.h"

inline int fAx2992(pack_mats_32x32 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax2992.data[i][j] = -bmats.A_10_17.data[i][j] - bmats.A_10_18.data[i][j] - bmats.A_10_19.data[i][j] - bmats.A_10_20.data[i][j] - bmats.A_10_21.data[i][j] - bmats.A_10_22.data[i][j] - bmats.A_10_25.data[i][j] - bmats.A_10_26.data[i][j] - bmats.A_10_27.data[i][j] - bmats.A_10_28.data[i][j] - bmats.A_10_29.data[i][j] - bmats.A_10_30.data[i][j] - bmats.A_10_31.data[i][j] - bmats.A_10_32.data[i][j] + bmats.Ax2836.data[i][j];
        }
    }
    return 0;
}
