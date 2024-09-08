#include "fAx855.h"

inline int fAx855(pack_mats_22x22 bmats) {
    int BL = bmats.A_1_1.shape[0];
    for (int i=0; i<BL; i++) {
        for (int j=0; j<BL; j++) {
            bmats.Ax855.data[i][j] = bmats.A_20_12.data[i][j] + bmats.A_20_13.data[i][j] + bmats.A_20_14.data[i][j] + bmats.A_20_17.data[i][j] + bmats.A_20_18.data[i][j] + bmats.A_20_19.data[i][j] + bmats.A_20_20.data[i][j] + bmats.A_20_21.data[i][j] + bmats.A_20_22.data[i][j];
        }
    }
    return 0;
}
