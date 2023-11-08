from flask import Flask, request, jsonify
from bs4 import BeautifulSoup
import requests
from flask import render_template
from flask_cors import CORS

app = Flask(__name__)
CORS(app)
@app.route('/')

def index():
    return render_template('index.html')

def scrape_your_data(search_query):
    
    search_url = f"https://news.tvbs.com.tw/news/searchresult/{search_query}/news"
    response = requests.get(search_url)
    soup = BeautifulSoup(response.text, "html.parser")

    main_tag = soup.find('main')
    elements_to_exclude = main_tag.select('.keyword, .search, .page-div, .sidebar_div')

    for element in elements_to_exclude:
        element.extract()

    li_elements = main_tag.find_all('li')

    scraped_data = []

    for li in li_elements:
        text = li.get_text()
        a_tag = li.find('a')
        if a_tag:
            link = a_tag.get('href')
        else:
            link = 'No link found'
        
        img_tag = li.find('img')
        if img_tag:
            img_src = img_tag.get('data-original')
        else:
            img_src = 'No image found'

        scraped_data.append({
            "Text": text,
            "Link": link,
            "Image URL": img_src
        })

    return scraped_data

@app.route('/api/scrape', methods=['GET'])
def api_scrape_data():
    search_query = request.args.get('search_query')
    if not search_query:
        return jsonify({"error": "Search query is required."}), 400

    scraped_data = scrape_your_data(search_query)
    return jsonify(scraped_data)

@app.route('/api/serverlink',methods=['GET'])
def api_return_result():
    search_query = request.args.get('search_query')
    if not search_query:
        return jsonify({"error": "Search query is required."}), 400

    scraped_data = scrape_your_data(search_query)
    return jsonify(scraped_data)

    

if __name__ == '__main__':
    app.run(debug=True)
