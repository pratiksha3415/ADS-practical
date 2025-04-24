from wordcloud import WordCloud
import matplotlib.pyplot as plt
import numpy as np
from PIL import Image, ImageDraw

def create_shape_mask(width=800, height=600, shape='circle'):
    mask = Image.new('RGB', (width, height), (255, 255, 255))
    draw = ImageDraw.Draw(mask)
    if shape == 'circle':
        draw.ellipse([0, 0, width, height], fill=(0, 0, 0))
    elif shape == 'star':
        points = [(width/2,0), (width*2/3,height/3), (width,height/2),
                  (width*2/3,height*2/3), (width/2,height),
                  (width/3,height*2/3), (0,height/2), (width/3,height/3)]
        draw.polygon(points, fill=(0, 0, 0))
   
    return np.array(mask)

file_path = r'C:\Users\Pratiksha\Desktop\ADS\sample.txt'

with open(file_path, 'r', encoding='utf-8') as file:
    text = file.read()

for shape in ['circle', 'star']:
    plt.figure(figsize=(10,5))
    wordcloud = WordCloud(width=800, height=600,
                          background_color='white',
                          mask=create_shape_mask(shape=shape),
                          contour_width=3,
                          contour_color='blue',
                          colormap='viridis').generate(text)
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    plt.title(f'{shape.capitalize()} Word Cloud')
    plt.show()