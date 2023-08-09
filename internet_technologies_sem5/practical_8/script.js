$(document).ready(function () {
    $("#btn").click(function () {
        $(".container").css("background-color", "#f9f9f9");
        $("h1, h2, h3, p, ul, li, button").css("color", "#333");

        $(".container").css("box-shadow", "0px 0px 20px rgba(0, 0, 0, 0.1)",);

        $("button").css({
            "background-color": "#e74c3c",
            "color": "#fff",
            "border": "none",
            "cursor": "not-allowed"
        });

        $("h1, h2, h3").css("border-radius", "8px");
    });
});
