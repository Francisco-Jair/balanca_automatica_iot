import requests
# url = "https://www.fast2sms.com/dev/bulk"
# payload = "sender_id=FSTSMS&message=test&language=english&route=p&numbers=9999999999,888888888"

# headers = {
#     'authorization': "YOUR_AUTH_KEY",
#     'Content-Type': "application/x-www-form-urlencoded",
#     'Cache-Control': "no-cache",
# }
# response = requests.request("POST", url, data=payload, headers=headers)
# print(response.text)

def enviar(data_h):
    url = f"https://whatsapp-jon.herokuapp.com/message/text?key=10"
    payload = {
        "message" : f"Sua caixa de papel estão com capacidade abaixo da capacidade estabelecida. sugestão de compra https://tinyurl.com/22ucn4d2, Registro: {data_h}",
        "id" : "558981113898"
    }
    data = requests.post(url, headers={'Authorization': 'Bearer 8343806'}, data=payload)
    print(data.status_code)
    return True