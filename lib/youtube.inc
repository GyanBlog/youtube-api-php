<?php

class YoutubeClient {
	var $apiKey;
	var $baseuri;

	function __construct($apiKey) {
		$this->apiKey = $apiKey;
		$this->baseuri = 'https://www.googleapis.com/youtube/v3';
	}

	function getVideoDetails($videoId) {
		$api = 'videos';
		$params = array(
			'key' => $this->apiKey,
		  'id' => $videoId,
		  'part' => 'snippet,contentDetails,topicDetails,statistics'
		);
		return $this->_doRestCall($api, $params);
	}

	/**
	 * Do GET rest api calls
	 * @param api, the api part you want to call
	 * @param params, query params
	 **/
	function _doRestCall($api, $params = false) {
	    $curl = curl_init();

			$url = sprintf("%s/%s", $this->baseuri, $api);
	    if (params) {
	        $url = sprintf("%s/%s?%s", $this->baseuri, $api, http_build_query($params));
	    }

	    curl_setopt($curl, CURLOPT_URL, $url);
	    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);

	    $result = curl_exec($curl);

	    curl_close($curl);

	    return json_decode($result);
	}
}
