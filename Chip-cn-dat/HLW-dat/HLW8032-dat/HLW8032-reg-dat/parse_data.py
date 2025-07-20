import math

def hex_to_decimal(hex_bytes_list):
    """Converts a list of 3 hex byte strings to a decimal integer."""
    hex_str = "".join(hex_bytes_list)
    return int(hex_str, 16)

def process_data_segment(segment):
    """
    Processes a 24-byte segment of hex data.
    Extracts V_para, V_data, C_para, C_data, performs calculations.
    """
    try:
        # Bytes are 0-indexed within the 24-byte segment
        # V_para: 3rd, 4th, 5th bytes (indices 2, 3, 4)
        v_para_hex = segment[2:5]
        # V_data: 6th, 7th, 8th bytes (indices 5, 6, 7)
        v_data_hex = segment[5:8]
        # C_para: 9th, 10th, 11th bytes (indices 8, 9, 10)
        c_para_hex = segment[8:11]
        # C_data: 12th, 13th, 14th bytes (indices 11, 12, 13)
        c_data_hex = segment[11:14]

        v_para = hex_to_decimal(v_para_hex)
        v_data = hex_to_decimal(v_data_hex)
        c_para = hex_to_decimal(c_para_hex)
        c_data = hex_to_decimal(c_data_hex)

        if v_data == 0:
            # print(f"Warning: V_data is zero in segment: {' '.join(segment)}. Skipping V calculations.")
            v_ratio_calc = 0.0
            v_para_div_v_data_times_factor = 0.0
        else:
            v_ratio_calc = v_para / v_data
            v_para_div_v_data_times_factor = v_ratio_calc * 1.88

        if c_data == 0:
            # print(f"Warning: C_data is zero in segment: {' '.join(segment)}. Skipping C calculations.")
            c_ratio_calc = 0.0
            c_para_div_c_data_times_factor = 0.0
        else:
            c_ratio_calc = c_para / c_data
            c_para_div_c_data_times_factor = c_ratio_calc * 0.003

        return (
            v_para,
            v_data,
            v_ratio_calc,
            v_para_div_v_data_times_factor,
            c_para,
            c_data,
            c_ratio_calc,
            c_para_div_c_data_times_factor,
        )
    except (ValueError, IndexError) as e:
        # print(f"Error processing segment {' '.join(segment)}: {e}")
        return None

def main():
    # Use the filepath provided in the data.txt comment
    # For simplicity, this script assumes data.txt is in the same directory
    # or you can provide the full path.
    input_filepath = r"D:\git-docs\edragon\edragon.github.io\Chip-cn-dat\HLW-dat\HLW8032-dat\HLW8032-reg-dat\data-SVC1038.txt" 
    # Example of full path:
    # input_filepath = r"d:\git-docs\edragon\edragon.github.io\Chip-cn-dat\HLW-dat\HLW8032-dat\HLW8032-reg-dat\data.txt"

    try:
        with open(input_filepath, "r") as f:
            raw_content = ""
            for line in f:
                if line.startswith("// filepath:"):
                    continue
                raw_content += line.strip() # Read the first data line
                break # Assuming all relevant hex data is on one line after comments
        
        if not raw_content:
            print(f"No data content found in {input_filepath}")
            return

        hex_values = raw_content.split()
        
        i = 0
        while i < len(hex_values):
            # Find the start of a segment "FA 5A" or "55 5A"
            ## if hex_values[i] == "55" and (i + 1) < len(hex_values) and hex_values[i+1] == "5A":
            
            if (hex_values[i] == "FA" or hex_values[i] == "55") and \
               (i + 1) < len(hex_values) and hex_values[i+1] == "5A":
                
                # Check if there are enough bytes for a full 24-byte segment
                # Segment includes the starting two bytes, so we need 22 more bytes. Total 24.
                if (i + 24) <= len(hex_values):
                    segment = hex_values[i : i + 24]
                    result = process_data_segment(segment)
                    if result:
                        (v_p, v_d, v_r, v_calc, c_p, c_d, c_r, c_calc) = result
                        print(
                            f"{v_p};{v_d};{v_r};{v_calc};"
                            f"{c_p};{c_d};{c_r};{c_calc}"
                        )
                    # Move to the start of the next potential segment
                    i += 24 
                else:
                    # Not enough bytes for a full segment from this "55 5A"
                    # print(f"Incomplete segment at index {i}. Remaining bytes: {len(hex_values) - i}")
                    break 
            else:
                # If not "55", or not "55 5A", move to the next byte to search for the start
                i += 1
                
    except FileNotFoundError:
        print(f"Error: File '{input_filepath}' not found.")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()