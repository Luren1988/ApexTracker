from pprint import pprint
import os
import sys
import json
import requests

def tracker(request):

    #細かいのはApex trackerのドキュメント参照
    apikey = os.environ.get('TRN-Api-Key','')
    request_json = request.get_json()
    # IDを設定　
    # psn -> PS  , pc -> origin  
    yourid = ""
    params = {"TRN-Api-Key":apikey}
    base_url = "https://public-api.tracker.gg/v2/apex/standard/profile/psn/{yourid}"

    session = requests.Session()
    
    try:
        req = session.get(base_url,params=params)
        if req.status_code == 200:
            req.close()
            res = json.loads(req.text)
            rank_info = res["data"]["segments"][0]["stats"]["rankScore"]
        else:
            rank_info = {}
    except:
        rank_info = {}

    return rank_info
