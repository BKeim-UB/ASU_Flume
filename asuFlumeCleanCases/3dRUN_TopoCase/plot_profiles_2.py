import os
import matplotlib.pyplot as plt

def read_line_xy(file_path):
    """Reads a line.xy file and returns the data as two lists: x and y."""
    x, y = [], []
    with open(file_path, 'r') as file:
        for line in file:
            # Skip commented lines
            if line.strip().startswith("#"):
                continue
            try:
                columns = line.split()
                x.append(float(columns[0]))
                y.append(float(columns[1]))
            except (IndexError, ValueError):
                pass  # Skip lines that can't be parsed
    return x, y

def plot_line_xy(base_dir):
    """Finds all line.xy files in the base directory and plots their data, saving each plot as a .jpg file."""
    output_counter = 1  # Initialize counter for sequential filenames
    for root, dirs, files in os.walk(base_dir):
        for file in files:
            if file == "line.xy":
                file_path = os.path.join(root, file)
                x, y = read_line_xy(file_path)

                # Extract the directory structure for labeling
                relative_path = os.path.relpath(file_path, base_dir)
                label = os.path.dirname(relative_path)

                # Check if the current line is "line1" or "line2" to flip axes
                if "line1" in label or "line2" in label:
                    x, y = y, x  # Flip axes

                # Create the plot
                plt.figure(figsize=(10, 6))
                plt.plot(x, y, label=label)
                plt.xlabel("X" if "line1" not in label and "line2" not in label else "Volume Fraction")
                plt.ylabel("Pressure (Pa)" if "line1" not in label and "line2" not in label else "Y")
                plt.legend(loc='best', fontsize='small')
                plt.grid(True)

                # Set x-axis limits for line1
                if "line1" in label:
                    plt.xlim(0, 1)
                    plt.ylim(0, 0.3)
                    plt.title(f"alpha.particles1 from {label}")

                # Set x-axis limits for line1
                if "line2" in label:
                    plt.xlim(0, 0.3)
                    plt.ylim(0, 0.3)
                    plt.title(f"alpha.particles2 from {label}")

                if "pressureLine" in label:
                     plt.title(f"alpha.particles1 from {label}")
                     plt.ylim(102420, 102460)
                    
                # Save the plot with sequential filenames
                output_filename = os.path.join(base_dir,f"{output_counter}.svg")
                plt.savefig(output_filename, format='svg')
                plt.close()

                # Increment the counter for the next plot
                output_counter += 1

# Set the base directory to your postProcessing folder
base_dir = "postProcessing"
plot_line_xy(base_dir)
