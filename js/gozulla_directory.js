
    function initiate_geolocation() {
        navigator.geolocation.getCurrentPosition(handle_geolocation_query, handle_errors);
    }

    function handle_errors(error)
    {
        switch (error.code)
        {
        case error.PERMISSION_DENIED:
            alert("user did not share geolocation data");
            break;

        case error.POSITION_UNAVAILABLE:
            alert("could not detect current position");
            break;

        case error.TIMEOUT:
            alert("retrieving position timed out");
            break;

        default:
            alert("unknown error");
            break;
        }
    }

    function handle_geolocation_query(position) {
        var latlon = position.coords.latitude + ',' + position.coords.longitude;
        var lat = position.coords.latitude;
        var lng = position.coords.longitude;


        var fwixurl = '/sites/all/modules/custom/gozula_directory/proxy_fwix.php?lat=' + lat + '&lng=' + lng + '&callback=?';

        //var fwixurl = 'http://geoapi.fwix.com/location.json?lat=' + lat + '&lng=' . lng . '&api_key=0514d0c66030&callback=?';
        $.getJSON(fwixurl,
        function(fwix) {
            document.getElementById("currentlocation").innerHTML += '<div class="current-location">Current location: ' + fwix.city + ', ' + fwix.province + '</div>';
            document.getElementById("currentlocation").innerHTML += '<div class="weather">Weather: ' + fwix.weather.conditions + ' ' + fwix.weather.temp_f + ' &deg;F</div><br /><br />';

        });


        var url = 'http://api.v3.factual.com/t/places.json?geo={"$circle":{"$center":[' + latlon + '],"$meters":80468}}&limit=10&filters={"$and":[{"name":{"$search":"surfshop, surf%20shop,surfing,surfboard,surfboards,surf"}},{"category":{"$in":"Shopping,Shopping > Sporting Goods,Sports %26 Recreation,Real Estate %26 Home Improvement > Storage"}}]}&KEY=8io424iJLjpIzY7Cx37T1hADLuUK6xbhwznLzDfz';

        var currentname = '';
        var previousname = '';

        document.getElementById("placeslist").innerHTML += '<div class="place_latlon">Current latitude/longitude: ' + latlon + '</div>';
        document.getElementById("placeslist").innerHTML += '<div class="place_accuracy">Accuracy: ' + position.coords.accuracy + ' meters</div>';

        $.getJSON(url,
        function(answer) {
            $.each(answer.response.data,
            function(i, result) {
                currentname = result.name;
                if (result.status == 1 && previousname !== currentname) {
                    document.getElementById("placeslist").innerHTML += '<div class="places">';
                    document.getElementById("placeslist").innerHTML += '<h3 class="place_name">' + result.name + '</h3>';
                    document.getElementById("placeslist").innerHTML += '<div class="place_address">' + result.address + '</div>';
                    document.getElementById("placeslist").innerHTML += '<div class="place_locality">' + result.locality + ' ' + result.region + ', ' + result.postcode + '</div>';
                    document.getElementById("placeslist").innerHTML += '<div class="place_phone">' + result.tel + '</div>';
                    if (result.email !== undefined) {
                        document.getElementById("placeslist").innerHTML += '<div class="place_website">' + result.email + '</div>';
                    }
                    if (result.website !== undefined) {
                        document.getElementById("placeslist").innerHTML += '<div class="place_website"><a href="' + result.website + '">' + result.website + '</a></div>';
                    }
                   /* document.getElementById("placeslist").innerHTML += '<div class="place_website">Latitude: ' + result.latitude + '</div>';
                    document.getElementById("placeslist").innerHTML += '<div class="place_website">Longitude: ' + result.longitude + '</div>';
                    if (result.category !== undefined) {
                        document.getElementById("placeslist").innerHTML += '<div class="place_website">Category: ' + result.category + '</div>';
                    }
                    else {
                        document.getElementById("placeslist").innerHTML += '<div class="place_website">This place isn\'t categorized</div>';
                    } */
                    document.getElementById("placeslist").innerHTML += '<div class="place_distance">Distance: ' + Math.round(result.$distance * 0.000621371192 * 10) / 10 + ' miles</div>';
                    /*document.getElementById("placeslist").innerHTML += '<div class="place_factual_id"">factual_id: ' + result.factual_id + '</div>';*/
                    document.getElementById("placeslist").innerHTML += '</div>'
                    previousname = currentname;
                }
            });
        });

    }


   