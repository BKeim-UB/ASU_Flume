import numpy as np
import sys
from stl import mesh

def generate_topography(xmin, xmax, ymin, ymax, x_values, elev_values, cellsize, output_file, stl_file=None):
    """
    Generate a topography raster where elevation is constant in the y direction and
    varies linearly in the x direction based on input points.

    Parameters:
        xmin, xmax, ymin, ymax: float
            Boundaries of the topography grid.
        x_values, elev_values: list of float
            Lists defining the linear change of elevation in the x direction.
        cellsize: float
            The resolution of the grid cells.
        output_file: str
            The path to save the output raster file in .asc format.
        stl_file: str, optional
            The path to save the output surface as an STL file.
    """
    # Validate inputs
    if len(x_values) != len(elev_values):
        raise ValueError("x_values and elev_values must have the same length.")

    # Generate x and y grid coordinates
    x_coords = np.arange(xmin, xmax + cellsize, cellsize)
    y_coords = np.arange(ymin, ymax + cellsize, cellsize)

    # Interpolate elevation for x coordinates
    elevation_profile = np.interp(x_coords, x_values, elev_values)

    # Create the elevation grid by repeating the elevation profile along the y axis
    elevation_grid = np.tile(elevation_profile, (len(y_coords), 1))

    # Write the grid to an ASCII raster file
    with open(output_file, 'w') as asc_file:
        asc_file.write(f"ncols {elevation_grid.shape[1]}\n")
        asc_file.write(f"nrows {elevation_grid.shape[0]}\n")
        asc_file.write(f"xllcorner {xmin}\n")
        asc_file.write(f"yllcorner {ymin}\n")
        asc_file.write(f"cellsize {cellsize}\n")
        asc_file.write(f"NODATA_value -9999\n")

        for row in elevation_grid[::-1]:  # Reverse rows to match raster origin at lower-left corner
            asc_file.write(" ".join(map(str, row)) + "\n")

    # Write the grid to an STL file if specified
    if stl_file:
        vertices = []
        faces = []

        # Generate vertices
        for j, y in enumerate(y_coords):
            for i, x in enumerate(x_coords):
                vertices.append([x, y, elevation_grid[j, i]])

        vertices = np.array(vertices)

        # Generate faces (triangles)
        ncols = len(x_coords)
        nrows = len(y_coords)

        for j in range(nrows - 1):
            for i in range(ncols - 1):
                # Define the corners of the cell
                v1 = j * ncols + i
                v2 = v1 + 1
                v3 = v1 + ncols
                v4 = v3 + 1

                # Two triangles per cell
                faces.append([v1, v2, v4])
                faces.append([v1, v4, v3])

        faces = np.array(faces)

        # Create the mesh
        surface = mesh.Mesh(np.zeros(faces.shape[0], dtype=mesh.Mesh.dtype))
        for i, f in enumerate(faces):
            for j in range(3):
                surface.vectors[i][j] = vertices[f[j], :]

        # Write to STL file
        surface.save(stl_file)

if __name__ == "__main__":
    # Example usage
    try:
        xmin, xmax = -0.1, 3.1
        ymin, ymax = -0.1, 0.48
        x_values = [-0.1, 0.45, 0.5, 0.55, 3.1]
        elev_values = [0, 0, -0.05, 0, 0]
        cellsize = 0.01
        output_file = "topography.asc"
        stl_file = "topography.stl"

        generate_topography(xmin, xmax, ymin, ymax, x_values, elev_values, cellsize, output_file, stl_file)
        print(f"Topography saved to {output_file} and {stl_file}")
    except Exception as e:
        print(f"Error: {e}", file=sys.stderr)
