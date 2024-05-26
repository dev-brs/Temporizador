def translate(msg):
    translated_msg = ""
    
    for word in msg:
        if word == '0xffffffff':
            translated_msg += "0"
        else:
            translated_msg += "1"
        
        translated_msg += ','
        
    return translated_msg

with open('conversor piskel/toTranslate.txt', 'r') as file:
    hex_values = file.read().split(", ")

translated_values = translate(hex_values)

with open('conversor piskel/translated_output.txt', 'w') as output_file:
    output_file.write(translated_values)

print("Arquivo traduzido e salvo com sucesso!")
