from PIL import Image
import numpy as np

def image_to_rgb_matrix(image_path):
    # Open the image
    img = Image.open(image_path)

    # Convert the image to RGB (if it's not already in that mode)
    img = img.convert('RGB')

    # Convert the image to a NumPy array
    rgb_matrix = np.array(img)

    return rgb_matrix

# Replace 'your_image_path.jpg' with the path to your image file
image_path = r'C:\Users\Honey\Pictures\Camera Roll\WIN_20230604_00_38_38_Pro.jpg'
rgb_matrix = image_to_rgb_matrix(image_path)
print(rgb_matrix.shape)
# Display the shape of the RGB matrix
h=0
for c in rgb_matrix:
    for b in c:
        print(b)
        h=h+1
        if h==10:
            break