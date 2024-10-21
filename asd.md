---
layout: default
title: ASD
---

## ملفات ASD

<ul>
  {% for file in site.static_files %}
    {% if file.path contains '/asd/' %}
      <li><a href="{{ file.path }}">{{ file.name }}</a></li>
    {% endif %}
  {% endfor %}
</ul>
