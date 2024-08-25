import re
import sympy as sp

# Original expression example
expr_str = "A_1_11-A_1_1+1/12*A_2_11-11/12*A_2_1+1/12*A_2_2+1/12*A_2_3+1/12*A_2_4+1/12*A_2_5+1/12*A_2_6+1/12*A_2_7+1/12*A_2_8+1/12*A_2_9+1/12*A_2_10+1/12*A_3_11-11/12*A_3_1+1/12*A_3_2+1/12*A_3_3+1/12*A_3_4+1/12*A_3_5+1/12*A_3_6+1/12*A_3_7+1/12*A_3_8+1/12*A_3_9+1/12*A_3_10+1/12*A_4_11-11/12*A_4_1+1/12*A_4_2+1/12*A_4_3+1/12*A_4_4+1/12*A_4_5+1/12*A_4_6+1/12*A_4_7+1/12*A_4_8+1/12*A_4_9+1/12*A_4_10+1/12*A_5_11-11/12*A_5_1+1/12*A_5_2+1/12*A_5_3+1/12*A_5_4+1/12*A_5_5+1/12*A_5_6+1/12*A_5_7+1/12*A_5_8+1/12*A_5_9+1/12*A_5_10+1/12*A_6_11-11/12*A_6_1+1/12*A_6_2+1/12*A_6_3+1/12*A_6_4+1/12*A_6_5+1/12*A_6_6+1/12*A_6_7+1/12*A_6_8+1/12*A_6_9+1/12*A_6_10+1/12*A_7_11-11/12*A_7_1+1/12*A_7_2+1/12*A_7_3+1/12*A_7_4+1/12*A_7_5+1/12*A_7_6+1/12*A_7_7+1/12*A_7_8+1/12*A_7_9+1/12*A_7_10+1/12*A_8_11-11/12*A_8_1+1/12*A_8_2+1/12*A_8_3+1/12*A_8_4+1/12*A_8_5+1/12*A_8_6+1/12*A_8_7+1/12*A_8_8+1/12*A_8_9+1/12*A_8_10+1/12*A_9_11-11/12*A_9_1+1/12*A_9_2+1/12*A_9_3+1/12*A_9_4+1/12*A_9_5+1/12*A_9_6+1/12*A_9_7+1/12*A_9_8+1/12*A_9_9+1/12*A_9_10+1/12*A_10_11-11/12*A_10_1+1/12*A_10_2+1/12*A_10_3+1/12*A_10_4+1/12*A_10_5+1/12*A_10_6+1/12*A_10_7+1/12*A_10_8+1/12*A_10_9+1/12*A_10_10-A_11_1"

# Updated regex pattern to match terms with or without explicit coefficients
pattern = r"([+-]?(\d+/\d+|\d+)?\*?)?(A_\d+_\d+)"

# Function to multiply coefficients by 12 and handle implicit coefficients
def symmul12(match):
    fraction_str = match.group(1)
    slash = match.group(2)
    term = match.group(3)

    if slash is None or fraction_str in ["+", "-"]:
        # Default coefficient is +1 or -1
        fraction = sp.Rational(f"{fraction_str}1") if fraction_str else sp.Rational(1)
    else:
        # Use the matched fraction or integer
        fraction = sp.Rational(fraction_str.replace('*', ''))

    # Multiply by 12
    simplified_fraction = fraction * 12

    # Construct the resulting string
    if simplified_fraction == 1:
        return f"+{term}"
    elif simplified_fraction == -1:
        return f"-{term}"
    elif simplified_fraction > 0:
        return f"+{simplified_fraction}*{term}"
    else:
        return f"{simplified_fraction}*{term}"

# Apply the function to all matches in the string
simplified_expr_str = re.sub(pattern, symmul12, expr_str)

print("Original Expression:", expr_str)
print("Simplified Expression:", simplified_expr_str)
