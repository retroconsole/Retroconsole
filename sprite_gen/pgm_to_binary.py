'''
Filename: pgm_to_binary.py
Author: Kaido Siimer
Date: 19.02.2019
Description: Changes .pgm raw 1bit monochrome files to code for 5110LCD retroconsole.
Notes: images.h will be overwritten if exists!
'''

'''
To use Create image in gimp, Select Image->Mode->Indexed-> 1bit monochrome,
Export as .PGM
Copy pgm to sprite_gen folder.
Run script.
Profit.
'''

import os

def find_resolution(binary):
    # PGM resolution starts from byte 42
    current = 42
    space = 0
    x = y = ""
    while binary[current] != 10:
        current += 1
        end = current
        if binary[current] == 32:
            space = current

    # Move cursor back to start of the reso.
    current = 42

    while current < space:
        x += chr(binary[current])
        current += 1

    current += 1

    while current < end:
        y += chr(binary[current])
        current += 1


    x, y = int(x), int(y)

    # End of reso + 5 bytes is start of image.
    return x, y, end + 5

def format_picture(binary, x, y, start_of_image):
    #Cut off overhead
    binary = binary[start_of_image:]

    current = 0
    row = 0
    image = [[] for x in range(y)]
    while current < len(binary):
        #If 0 then black
        if binary[current] == 0:
            image[row].append(1)
        #else white
        else:
            image[row].append(0)
        current += 1
        if current != 0 and current % x == 0:
            row += 1

    return image

def print_image(image):
    started = 0
    for row in image:
        if started == 1:
            print()
        started = 1
        for pixel in row:
            print(pixel,end="")
    print()


def image_to_code(image, x, y, picture_name):
    if y % 8 != 0:
        addition = 1
    else:
        addition = 0
    with open("images.h", "a+") as code_file:
        # Creates initing code for C.
        init_code = "Sprite " + picture_name + "Sprite = {"+ str(x) +", "+ str(y) +", "+ str(int(y/8) + addition) + ", *"+ picture_name +"};\n" 

        #Creates data code for C
        code_start = "static const uint8_t " + picture_name +"[]["+ str(int(y/8) + addition) +"] PROGMEM= {\n"

        pixel_counter = 0
        current_pixel_in_row = 0
        row_counter = 0
        initation_codes.append(init_code)
        code_file.write(code_start)
        for row in image:
            code_file.write("{")
            for pixel in row:
                # Deal with bits
                if pixel_counter == 8:
                    pixel_counter = 0
                if pixel_counter == 0:
                    code_file.write("0b")

                # Write bit
                code_file.write(str(pixel))
                pixel_counter += 1
                current_pixel_in_row += 1

                # Handle separators
                if pixel_counter == 8 and current_pixel_in_row != len(row):
                    code_file.write(", ")
            
            # 0 padding to end
            if pixel_counter != 7:
                code_file.write("0" * (8 - pixel_counter))
            current_pixel_in_row = 0
            pixel_counter = 0

            # close curly brackets
            if row_counter != len(image) - 1:
                code_file.write("},\n")
            else:
                code_file.write("}\n")
            row_counter += 1

        code_file.write("};\n\n")

def write_init_codes():
    with open("images.h", "a+") as code_file:
        for item in initation_codes:
            code_file.write(item)


if __name__ == "__main__":

    initation_codes = []

    # Get ./ dir file list
    filelist=os.listdir()
    for file in filelist[:]:
        if not(file.endswith(".pgm")):
            filelist.remove(file)

    # Iterate over .pgm files
    if filelist != []:
        with open("images.h", "w+") as code_file:
            includes = "#include <avr/pgmspace.h>\n"
            code_file.write(includes)
        for file in filelist:
            file_name = file.split(".")[0]
            with open(file, "rb") as imageFile:
                f = imageFile.read()
                # Get reso of image
                x, y, start_of_image = find_resolution(f)

                # Get image
                image = format_picture(f, x, y, start_of_image)

                # Image to code
                image_to_code(image, y, x, file_name)
                
        write_init_codes()

        print("Generation done, sprites generated: " + str(len(filelist)))
    
    else:
        print("No files found.")



