<?php
include './lib/youtube.inc';

$youtubeClient = new YoutubeClient('key');

$result = $youtubeClient->getVideoDetails('xxx');
print '<pre>'.print_r($result, TRUE).'</pre>';
